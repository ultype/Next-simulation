ifndef $("${CFLAGS}")
	CFLAGS=-I/usr/local/include/cifx/
endif
 
all:
	$(CC) ISASample.c $(LIBS) $(CFLAGS) -I. -lcifx -lrt -lpthread -o ISASample
clean:
	rm -f *.o ISASample
