APP=crypt_test

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	gcc -Wall -lcrypt -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe
