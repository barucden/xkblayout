.PHONY: clean

CFLAGS = -Wall -O2

build: main.c
	${CC} ${CFLAGS} -o xkblayout main.c -lX11

clean:
	rm -f xkblayout
