TARGET	= main.exe
CFLAGS	= -g -c -D_POSIX_C_SOURCE -D_GNU_SOURCE -Iinclude
CLFAGS += -std=c99 -Wimplicit-function-declaration -Werror
CFLAGS +=

LDFLAGS =

.PHONY: all
all: main.exe

main.exe: main.o queue.o simulator.o
	gcc $^ -o $@ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o *.dSYM