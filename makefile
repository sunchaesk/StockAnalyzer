
exe = c
CFLAGS = -Wall -g

$(exe):main.c
	gcc ${CFLAGS} main.c -o ${exe}

clean:
	rm ${exe}

debug:
	gdb ./${exe}
