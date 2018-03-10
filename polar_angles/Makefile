APP=polar_angles

all: clean comp test

clean:
	rm -fr ./${APP}.exe

comp:
	g++ -Wall -lm -o ${APP}.exe ${APP}.cpp

test:
	./${APP}.exe < input > result && diff -q result expected && echo && echo SUCCESS T1
	./${APP}.exe < input2 > result2 && diff -q result2 expected2 && echo && echo SUCCESS T2
	./${APP}.exe < input3 > result3 && diff -q result3 expected3 && echo && echo SUCCESS T3
	./${APP}.exe < input4 > result4 && diff -q result4 expected4 && echo && echo SUCCESS T4

