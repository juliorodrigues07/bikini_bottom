all: bikini_bottom.o
	gcc bikini_bottom.o main.c -o bob -lGL -lGLU -lglut -lm

bikini_bottom.o: bikini_bottom.h
	gcc -c bikini_bottom.c

clean:
	rm -rf *.o
	rm -rf bob

run:
	./bob