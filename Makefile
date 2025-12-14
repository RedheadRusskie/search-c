CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -I include
SRC = src/main.c src/search.c src/util.c
OUT = search
PREFIX = /usr/local

.PHONY: all install uninstall clean

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

install: $(OUT)
	install -d $(PREFIX)/bin
	install -m 755 $(OUT) $(PREFIX)/bin/$(OUT)

uninstall:
	rm -f $(PREFIX)/bin/$(OUT)

clean:
	rm -f $(OUT)
