#Modified by Eduardo at 01/18
	#Change BFILE name and change mkdir path. 

WFLAG  = -Wall -Werror
CFLAG  = 
TARGET = bin
OPT    = -O3 -DNDEBUG -static
RM     = rm
TAG    = ctags
CC     = g++ -std=c++11 $(OPT) $(WFLAG) $(CFLAG) -I.

CC_OBJS = main.o
#IO_OBJS = io/io.o io/lef.o io/def.o io/rpt.o io/guide.o io/weight.o
#DB_OBJS = db/db.o db/net.cpp #db/guide.o

OBJS = $(CC_OBJS) #$(IO_OBJS) $(DB_OBJS)

SRCS = ${OBJS:%.o=%.cpp}
BFILE = eduardo
AFILE = eduardo.a

define copy_build
	mkdir -p ../$(TARGET)
	mv -u $(BFILE) ../$(TARGET)
	cp -u data/* ../$(TARGET)
endef

.PHONY: all
all: $(BFILE)

.PHONY: install
install: $(BFILE)
	$(call copy_build)

#$(BFILE): $(DEF_OBJS) $(LEF_OBJS) $(OBJS)
$(BFILE): $(OBJS)
	$(CC) -o $(BFILE) $(OBJS) $(LIB_OBJS)
	$(call copy_build)

%.o : %.cpp
	$(CC) -o $*.o -c $*.cpp

.PHONY: clean
clean:
	$(RM) -f */*.o *.o
	$(RM) -f $(BFILE) $(AFILE) core.*

.PHONY: cleanall
cleanall:
	$(RM) -f */*.o *.o
	$(RM) -f $(BFILE) $(AFILE) core.*
