TARGET = libFileMgr.so
OBJS = FileMgr.o  FileSystem.o

BINDIR = ../dist

CPP = g++
CPPFLAGS = -g -Wall -std=c++11 -fPIC

all : clean $(TARGET)

$(TARGET) : $(OBJS)
	mkdir -p $(BINDIR)
	$(CPP) -shared -o $(BINDIR)/$@ $^

$.o : $.cpp
	$(CPP) $(CPPFLAGS) -c $<

clean : 
	rm -rf $(BINDIR)/$(TARGET) $(OBJS)
