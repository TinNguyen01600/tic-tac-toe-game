all: compile run

compile:
	gcc C:\game\main.c C:\game\game.c C:\game\game.h -lm -o Project1 -I.
run:
	./Project1

clean:
	rm -f compile run

