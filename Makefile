CC=gcc
CCFLAGS=-std=C99

all: clean genincls

genincls:
	xcopy src/*.h include /e

clean:
	rmdir include /s
	mkdir include

	rmdir examples/bin /s
	mkdir examples/bin
