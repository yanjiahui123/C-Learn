SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:%.c=%)
CC:=gcc
all:$(OBJS)
%:%.c
	$(CC) $< -o $@
.PHONY:clean
clean:
	rm -rf $(OBJS)
