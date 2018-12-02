#include "nxbus_engine.h"
#include <hiredis.h>

static redisContext *c;
static redisReply *reply;

void nxbus_init(void) {
    unsigned int j;

    const char *hostname = "127.0.0.1";
    int port = 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }
    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);
    return 0;
}

void nxbus_deinit(void) {
    /* Disconnects and frees the context */
    redisFree(c);
}

int nxbus_mset_vec(const char *key_name, double *vector, size_t dimension) {
    int idx = 0;
    int rc = 0;
    reply = redisCommand(c,"MULTI");
    freeReplyObject(reply);
    for (idx = 0; idx < dimension; ++idx) {
        reply = redisCommand(c,"SET %s[%d] %f ", key_name, idx, vector[idx]);
        freeReplyObject(reply);
    }

    reply = redisCommand(c,"EXEC");
    for (idx = 0; idx < dimension; ++idx) {
        if(reply->element[idx]->type == REDIS_REPLY_ERROR) {
            printf("EXEC: %s\n", reply->str);
            rc |= 0x1;
        }
    }
    freeReplyObject(reply);

    return rc;
}

int nxbus_mget_vec(const char *key_name, double *vector, size_t dimension) {
    double temp;
    int idx = 0;
    int rc = 0;
    reply = redisCommand(c,"MULTI");
    freeReplyObject(reply);
    for (idx = 0; idx < dimension; ++idx) {
        reply = redisCommand(c,"GET %s[%d]", key_name, idx);
        freeReplyObject(reply);
    }

    reply = redisCommand(c,"EXEC");
    for (idx = 0; idx < dimension; ++idx) {
        if(reply->element[idx]->type == REDIS_REPLY_ERROR) {
            printf("EXEC: %s\n", reply->str);
            rc |= 0x1;
        }
        sscanf(reply->element[idx]->str, "%lf", &vector[idx]);
    }
    freeReplyObject(reply);

    return rc;
}
