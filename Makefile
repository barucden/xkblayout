.PHONY: clean install

PREFIX=~/.bin/
CFLAGS = -Wall -O2

xkblayout: main.c
	${CC} ${CFLAGS} -o xkblayout main.c -lX11
clean:
	rm -f xkblayout

install: xkblayout
	install -m 0755 xkblayout ${PREFIX}

