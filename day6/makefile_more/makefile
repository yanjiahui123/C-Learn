CC:=gcc
SRCS:=$(wildcard *.c)
BINS:=$(SRCS:%.c=%)
LINKERFLAGS:=-lpthread
all:$(BINS)
%:%.c
	$(CC) $< -o $@ $(LINKERFLAGS)
.PHONY:clean
clean:
	rm -rf $(BINS)
