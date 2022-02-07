GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRC = $(wildcard *.c)
TAR = $(SRC:.c=.o)

.PHONY: all clean

all: $(TAR)

%.o: %.c
	$(GCC) $(CFLAGS) -c $<
	$(GCC) -o chain $(TAR) #Temporary addition to create executable. Ask Jack if this should be edited?

clean:
	rm -f $(TAR)
