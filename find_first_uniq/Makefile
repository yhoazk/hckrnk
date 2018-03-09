APP=find_first_uniq

all: clean comp run


clean:
	rm -fr ./${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe < input



