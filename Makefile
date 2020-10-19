SOURCES=src/*.cpp
CFLAGS=-std=c++20 -g

.PHONY: clean

all: ${SOURCES}
	clang++ ${CFLAGS} ${SOURCES} -o raytracer

run: raytracer
	./raytracer a.ppm

clean:
	rm -f raytracer
	rm -f *.ppm

