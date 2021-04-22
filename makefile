
exe = c
CFLAGS = -Wall -g
CLIBS = -lm
CSRC = main.c portfolio.c readf.c

$(exe):main.c
	gcc ${CFLAGS} ${CSRC} ${CLIBS} -o ${exe}

clean:
	rm ${exe}

debug:
	gdb ./${exe}
