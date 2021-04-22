
exe = c
CFLAGS =  -g
CLIBS = -lm
CSRC = main.c

$(exe):main.c
	gcc ${CFLAGS} ${CSRC} ${CLIBS} -o ${exe}

clean:
	rm ${exe}

debug:
	gdb ./${exe}
