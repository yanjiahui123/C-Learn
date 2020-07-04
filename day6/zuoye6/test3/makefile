SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:%.c=%)
CC:=gcc
CTAGS:=-g
all:$(OBJS)
%:%.c
	$(CC) $< -o $@ $(CTAGS)
.PHONY:clean
clean:
	rm -rf $(OBJS)
