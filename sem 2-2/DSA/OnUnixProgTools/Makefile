CC=gcc
LD=gcc
RM=rm -f
CFLAGS = -c -D NDEBUG
DBGFLAGS = -c -g
LDFLAGS = 
SRCS:=$(patsubst %.c,%,$(wildcard *.c))
OBJS:=$(patsubst %.c,%.o,$(wildcard *.c))
EXECS:=$(patsubst %.c,x%,$(wildcard *.c))
MAIN=$(EXECS)
all:$(MAIN)
$(MAIN):$(OBJS)
	for name in $(SRCS) ; do $(LD) $(LDFLAGS) $$name.o -o x$$name ; done
%.o:%.c
	for name in $(SRCS) ; do $(CC) $(CFLAGS) $$name.c -o $$name.o ; done
debug:*.c
	for name in $(SRCS) ; do $(CC) $(DBGFLAGS) $$name.c -o $$name.o ; done
clean:
	for name in $(OBJS) ; do $(RM) $$name ; done
	for name in $(EXECS) ; do $(RM) $$name ; done
 
