CC_FLAGS=-g

all: run.o world.o input.o point.o player.o screen.o
	gcc ${CC_FLAGS} run.o world.o input.o point.o player.o screen.o -lncurses -o run

clean:
	rm *.o run
