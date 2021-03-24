
PREFIX=~/.bin/
CFLAGS = -Wall -O2

clean:
	rm -f xkblayout

install: xkblayout
	install -m 0755 xkblayout ${PREFIX}

xkblayout: main.c
	${CC} ${CFLAGS} -o xkblayout main.c -lX11

.PHONY: clean install
