APP=insert_tail

all: clean comp run

clean:
	rm -rf ./${APP}.exe


comp:
	g++ -std=gnu++11 -Wall -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
