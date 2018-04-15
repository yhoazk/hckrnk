APP=test
all: clean comp generate

clean:
	rm -rf ./${APP}.exe

generate:
	./${APP}.exe --gtest_output="xml:./report.xml"

comp:
	#g++ -Wall -lgtest_main -L/usr/local/lib -o ${APP}.exe ${APP}.cpp
	#g++ -g  -lgtest -lgtest_main -lpthread -L/usr/local/lib -I/usr/local/include -o ${APP}.exe ${APP}.cpp
#	g++   -lgtest  -lpthread  -o ${APP}.exe  ${APP}.cpp <- does not works
	g++  -g ${APP}.cpp -lgtest  -lpthread  -o ${APP}.exe # <- WORKS
	#g++ test.cpp  -o ${APP}.exe -lgtest -lpthread


### The libraries shall be specified at the end of the g++ command.
