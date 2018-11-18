APP=find_0

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	clang++ -Wall -Wextra -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
