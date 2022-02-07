GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRC = $(wildcard *.c)
TAR = $(SRC:.c=.o)

.PHONY: all clean

all: $(TAR)

%.o: %.c
	$(GCC) $(CFLAGS) -c $<
	$(GCC) -o chain $(TAR)

clean:
	rm -f $(TAR)
