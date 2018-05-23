APP=cats_n_mouse

all: clean comp test

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -pipe -Wall -g -O3 ${APP}.cpp -o ${APP}.exe

test:
	./${APP}.exe < input > result
	diff -q result expected && echo OK
