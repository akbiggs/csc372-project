CC_FLAGS=-g

all: run.o world.o input.o point.o player.o collectible.o screen.o
	gcc ${CC_FLAGS} run.o world.o input.o point.o player.o collectible.o screen.o -lncurses -o run

clean:
	rm *.o run
