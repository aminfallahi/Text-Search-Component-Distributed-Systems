TARGET = ExplicitClient

EXECDIR = ./Client
LIBDIR1 = ./FileMgrComp
LIBDIR2 = ./TextSearchComp
BINDIR = ./dist


all : clean build

clean : 
	cd $(LIBDIR1) && $(MAKE) clean
	cd $(LIBDIR2) && $(MAKE) clean
	cd $(EXECDIR) && $(MAKE) clean

build :
	cd $(LIBDIR1) && $(MAKE)
	cd $(LIBDIR2) && $(MAKE)
	cd $(EXECDIR) && $(MAKE)

run:
	cd $(EXECDIR) && $(MAKE) run
