APP=crypt_test

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	g++ -Wall -lcrypt -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
