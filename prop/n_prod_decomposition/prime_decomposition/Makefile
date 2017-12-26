APP?=prime_decomposition

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe -g ${APP}.cpp


run:
	./${APP}.exe < input
