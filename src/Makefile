WFLAG  = -Wall -Werror
ifeq ($(PRINT),1)
	CFLAG  = -DPRINT_EXEC
endif
TARGET = bin
OPT    = -O3 -static
RM     = rm
TAG    = ctags
CC     = g++ -std=c++11 $(OPT) $(WFLAG) $(CFLAG) -I.

CC_OBJS = main.o
INFRA_OBJS = infra/state.o infra/node.o infra/problem.o infra/solver.o
#IO_OBJS = io/io.o io/lef.o io/def.o io/rpt.o io/guide.o io/weight.o

OBJS = $(CC_OBJS) $(INFRA_OBJS)

SRCS = ${OBJS:%.o=%.cpp}
BFILE = miss_cann
AFILE = miss_cann.a

define copy_build
	mkdir -p ../$(TARGET)
	mv -u $(BFILE) ../$(TARGET)
endef

.PHONY: all
all: $(BFILE)

.PHONY: install
install: $(BFILE)
	$(call copy_build)

$(BFILE): $(OBJS)
	$(CC) -o $(BFILE) $(OBJS)
	$(call copy_build)

%.o : %.cpp
	$(CC) -o $*.o -c $*.cpp

.PHONY: clean
clean:
	$(RM) -f */*.o *.o
	$(RM) -f $(BFILE) $(AFILE)

.PHONY: cleanAll
cleanAll:
	$(RM) -f */*.o *.o
	$(RM) -f $(BFILE) $(AFILE)
	$(RM) -f ../$(TARGET)/$(BFILE)

.PHONY: run332
run332:
	../bin/miss_cann -m 3 -c 3 -bc 2