SOURCES=src/*.cpp
CFLAGS=-std=c++20 -g

.PHONY: clean

all: ${SOURCES}
	clang++ ${CFLAGS} ${SOURCES} -o render

run: raytracer
	./render a.ppm

clean:
	rm -f render 
	rm -f *.ppm

