APP=polar_angles

all: clean comp test

clean:
	rm -fr ./${APP}.exe

comp:
	g++ -Wall -lm -o ${APP}.exe ${APP}.cpp

test:
	#./${APP}.exe < input > result && diff -q result expected && echo && echo SUCCESS T1
	./${APP}.exe < input2 > result2 && diff -q result2 expected2 && echo && echo SUCCESS T2

