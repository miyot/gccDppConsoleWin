# Makefile - gccDppConsole

ifndef CFG
CFG=Debug
endif
CC=gcc
CFLAGS=-m32 
CXX=g++
CXXFLAGS=$(CFLAGS)
ifeq "$(CFG)" "Debug"
CFLAGS+= -W -O0 -fexceptions -I../gccDppConsoleWin/DeviceIO/ -I../gccDppConsoleWin/ -g -fno-inline -D_DEBUG -D_CONSOLE -std=c++11
LD=$(CXX) $(CXXFLAGS)
LDFLAGS=
LDFLAGS+= -L../gccDppConsoleWin/DeviceIO/
LIBS+=-lstdc++ -lm -static -llibusb
ifndef TARGET
TARGET=gccDppConsole.exe
endif
ifeq "$(CFG)" "Release"
CFLAGS+= -W -O2 -fexceptions -I../gccDppConsoleWin/DeviceIO/ -I../gccDppConsoleWin/ -g -fno-inline -DNDEBUG -D_CONSOLE -std=c++11
LD=$(CXX) $(CXXFLAGS)
LDFLAGS=
LDFLAGS+= -L../gccDppConsoleWin/DeviceIO/
LIBS+=-lstdc++ -lm -static -llibusb
ifndef TARGET
TARGET=gccDppConsole.exe
endif
endif
endif
ifndef TARGET
TARGET=gccDppConsole.exe
endif
.PHONY: all
all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.res: %.rc
	$(RC) $(CPPFLAGS) -o $@ -i $<

SOURCE_FILES= \
	./ConsoleHelper.cpp \
	./DeviceIO/AsciiCmdUtilities.cpp \
	./DeviceIO/DP5Protocol.cpp \
	./DeviceIO/DP5Status.cpp \
	./DeviceIO/DppUtilities.cpp \
	./DeviceIO/ParsePacket.cpp \
	./DeviceIO/SendCommand.cpp \
	./DeviceIO/DppLibUsb.cpp \
	./stringex.cpp \
	./gccDppConsole.cpp

HEADER_FILES= \
	./ConsoleHelper.h \
	./DeviceIO/AsciiCmdUtilities.h \
	./DeviceIO/DP5Protocol.h \
	./DeviceIO/DP5Status.h \
	./DeviceIO/DppConst.h \
	./DeviceIO/DppUtilities.h \
	./DeviceIO/ParsePacket.h \
	./DeviceIO/SendCommand.h \
	./DeviceIO/DppLibUsb.h \
	./DeviceIO/libusb.h \
	./stringex.h \
	./stringSplit.h

OBJ_FILES= \
	./ConsoleHelper.o \
	./AsciiCmdUtilities.o \
	./DP5Protocol.o \
	./DP5Status.o \
	./DppUtilities.o \
	./ParsePacket.o \
	./SendCommand.o \
	./DppLibUsb.o \
	./stringex.o \
	./gccDppConsole.o 

RESOURCE_FILES= \

SRCS=$(SOURCE_FILES) $(HEADER_FILES) $(RESOURCE_FILES) 

OBJS=$(patsubst %.rc,%.res,$(patsubst %.cxx,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(filter %.c %.cc %.cpp %.cxx %.rc,$(SRCS)))))))

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJ_FILES) $(LIBS)

.PHONY: clean
clean:
	-rm -f -v $(OBJS) $(TARGET) gccDppConsole.dep

.PHONY: depends
depends:
	-$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM $(filter %.c %.cc %.cpp %.cxx,$(SRCS)) > gccDppConsole.dep

-include gccDppConsole.dep

