SOURCES=src/*.cpp
CFLAGS=-std=c++20 -g -Wall

.PHONY: clean

all: ${SOURCES}
	clang++ ${CFLAGS} ${SOURCES} -o raytracer

clean:
	rm -f raytracer
	rm -f *.ppm

