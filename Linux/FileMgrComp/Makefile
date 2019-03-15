TARGET = libFileMgr.so
OBJS = FileMgr.o  FileSystem.o

BINDIR = ../dist

CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -fPIC

.PHONY : all clean

all : clean $(TARGET)

$(TARGET) : $(OBJS)
	mkdir -p $(BINDIR)
	$(CXX) -shared -o $(BINDIR)/$@ $^

$.o : $.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean : 
	rm -rf $(BINDIR)/$(TARGET) $(OBJS)
