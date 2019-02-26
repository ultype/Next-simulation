ifndef $("${CFLAGS}")
	CFLAGS=-I/usr/local/include/cifx/
endif

all:
	 $(CXX) -g cifXLoadModule.cpp Cifx_LoadableModules_Start_Only_RCX_CMD.cpp Cifx_LoadableModules_Start_and_Load_with_RCX_CMD.cpp Cifx_LoadableModules_Start_and_Load_with_CIFX_API.cpp $(CFLAGS) $(LIBS) -I. -lcifx -lrt -lpthread -o LoadModule
clean:
	rm -f *.o LoadModule
