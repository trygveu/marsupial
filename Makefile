CFLAGS = -Wall -I ./include

all: bin/marsupial

bin/marsupial: src/main.c src/marsupial.c include/marsupial/marsupial.h | bin
	gcc $^ ${CFLAGS} -o $@ 

bin:
	mkdir -p bin

clean:
	rm build/marsupial
