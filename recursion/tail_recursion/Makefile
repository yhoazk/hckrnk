APP=tail_recursion

all: clean disass disasso1 comp run

clean:
	rm -rf ./${APP}.exe

disass:
	gcc -S ${APP}.c

disasso1:
	gcc -S -O2 ${APP}.c -o ${APP}_opt.s

comp:
	gcc ${APP}.c -o ${APP}.exe

run:
	./${APP}.exe < atoi_input
