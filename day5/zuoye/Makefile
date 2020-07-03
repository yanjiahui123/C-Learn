SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
ELF:=main
CC:=gcc
CFLAGS:=-g -Wall
$(ELF):$(OBJS)
	$(CC) $(OBJS) -o $(ELF) -lmulti
.PHONY:clean
clean:
	rm -rf $(OBJS) $(ELF)
