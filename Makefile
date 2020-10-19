SOURCES=src/*.cpp
CFLAGS=-std=c++20 -g
OUTFILE=render

.PHONY: clean

all: ${SOURCES}
	clang++ ${CFLAGS} ${SOURCES} -o ${OUTFILE}

run: ${OUTFILE}
	./${OUTFILE} a.ppm

clean:
	rm -f ${OUTFILE}
	rm -f *.ppm

