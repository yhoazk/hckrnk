APP=barcode_4state
all: clean comp run

clean:
	@rm -rf ./${APP}.exe

comp:
	@g++ -Wall -g -o ${APP}.exe ${APP}.cpp

run:
	@./${APP}.exe < input
