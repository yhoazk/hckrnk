APP?=getShannonEntropy

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe -g ${APP}.cpp


run:
	./${APP}.exe < input
	./${APP}.exe < input0
	./${APP}.exe < input1
