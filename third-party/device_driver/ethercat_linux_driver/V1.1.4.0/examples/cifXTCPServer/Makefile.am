bin_PROGRAMS = cifXTCPServer
AUTOMAKE_OPTIONS = subdir-objects

cifXTCPServer_SOURCES = TCPServer.c TCPConnector.c OS_Specific.c cifXDownloadHook.c Marshaller/CifXTransport.c Marshaller/HilMarshaller.c

cifXTCPServer_CFLAGS   = @CFLAGS@ -Wall -D_GNU_SOURCE -D_REENTRANT @libcifx_CFLAGS@ @PCIACCESS_CFLAGS@
cifXTCPServer_CPPFLAGS = @CPPFLAGS@ -Wall -I./ -I./Marshaller -I./Marshaller/APIHeader
cifXTCPServer_LDFLAGS  = -lpthread -lcifx @libcifx_LIBS@ @PCIACCESS_LIBS@
cifXTCPServer_LDADD    = -lpthread -lcifx @libcifx_LIBS@ @PCIACCESS_LIBS@

cifXTCPServer_CXXFLAGS = @CFLAGS@ -Wall -D_GNU_SOURCE -D_REENTRANT @libcifx_CFLAGS@ @PCIACCESS_CFLAGS@
