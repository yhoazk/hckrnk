APP=repeated_string

all: clean comp test

clean:
	@rm -rf ${APP}.exe

comp:
	@g++ -g -Wall -o ${APP}.exe ${APP}.cpp

test:
	@./${APP}.exe < input > result && diff -q result expected && echo PASSED
