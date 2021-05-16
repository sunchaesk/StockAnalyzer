
exe = c
CFLAGS =  -g
CLIBS = -lm
CSRC = main.c

$(exe):main.c
	gcc ${CFLAGS} -Wall -fno-stack-protector  ${CSRC} ${CLIBS} -o ${exe}
test:main.c
	gcc ${CFLAGS} ${CSRC} ${CLIBS} -o ${exe}

clean:
	rm ${exe}

debug:
	gdb ./${exe}
