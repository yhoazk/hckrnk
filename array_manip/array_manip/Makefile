APP=array_manipulation

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe < input > result
	diff -p result expected && echo OK
