SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:%.c=%)
CC:=gcc
CFLAGS:=-g
all:$(OBJS)
%:%.c
	$(CC) $< -o $@ $(CFLAGS)
.PHONY:clean
clean:
	rm -rf $(OBJS)
