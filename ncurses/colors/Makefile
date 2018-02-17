APP=colors

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	gcc -o ${APP}.exe -lncurses -Wall ${APP}.c

run:
	./${APP}.exe
