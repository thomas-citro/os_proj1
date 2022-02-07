GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRC = $(wildcard *.c)
TAR = $(SRC:.c=.o)

.PHONY: all clean

all: $(TAR)

%.o: %.c
	$(GCC) $(CFLAGS) -c $<
	$(GCC) -o chain $(TAR) 
# ^ Second line there is what I added to create executable. Ask Jack if this should be edited/changed?

clean:
	rm -f $(TAR)
