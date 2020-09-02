SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:%.c=%)
CC:=gcc
all:$(OBJS)
%:%.c
	$(CC) $< -o $@ -pthread
.PHONY:clean
clean:
	rm $(OBJS)
