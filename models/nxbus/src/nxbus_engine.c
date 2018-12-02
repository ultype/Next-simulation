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

void nxbus_mset_vec(const char *key_name, double *vector, size_t dimension) {
    reply = redisCommand(c,"MSET %s[0] %f %s[1] %f %s[2] %f",
                         key_name, vector[0],
                         key_name, vector[1],
                         key_name, vector[2]);
    if(reply->type == REDIS_REPLY_ERROR)
        printf("MSET: %s\n", reply->str);
    freeReplyObject(reply);
}

void nxbus_mget_vec(const char *key_name, double *vector, size_t dimension) {
    double temp;
    reply = redisCommand(c,"MGET %s[0] %s[1] %s[2]", key_name, key_name, key_name);
    if(reply->type == REDIS_REPLY_ERROR)
        printf("MGET: %s\n", reply->str);
    sscanf(reply->element[0]->str, "%lf", &vector[0]);
    sscanf(reply->element[1]->str, "%lf", &vector[1]);
    sscanf(reply->element[2]->str, "%lf", &vector[2]);
    freeReplyObject(reply);
}