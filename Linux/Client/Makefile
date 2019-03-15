TARGET = Client
OBJS = Client.o


BINDIR = ../dist

CXX = g++
CXXFLAGS = -g -Wall -std=c++11
LIB = -ldl

.PHONY : all clean 

all : clean $(TARGET)

$(TARGET) : $(OBJS)
	mkdir -p $(BINDIR)    &&    $(CXX) -o $(BINDIR)/$@ $^  $(LIB)

$.o : $.cpp
	$(CXX) $(CXXFLAGS)  -c $<   

clean : 
	rm -rf $(BINDIR)/$(TARGET) $(OBJS)

run :
	cd $(BINDIR) &&	./$(TARGET)
