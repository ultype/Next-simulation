ifndef $("${CFLAGS}")
	CFLAGS=-I/usr/local/include/cifx/
endif

all:
	$(CC) demo_funcs.c spi_sample.c $(CFLAGS) $(LIBS) -lcifx -lpthread -lrt -o spisample
clean:
	rm -f *.o spisample
