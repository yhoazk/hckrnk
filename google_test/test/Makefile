APP=test
all: clean comp run

clean:
	rm -rf ./${APP}.exe

run:
	./${APP}.exe


comp:
	#g++ -Wall -lgtest_main -L/usr/local/lib -o ${APP}.exe ${APP}.cpp
	#g++ -g  -lgtest -lgtest_main -lpthread -L/usr/local/lib -I/usr/local/include -o ${APP}.exe ${APP}.cpp
#	g++   -lgtest  -lpthread  -o ${APP}.exe  ${APP}.cpp <- does not works
	g++   ${APP}.cpp -lgtest  -lpthread  -o ${APP}.exe # <- WORKS
	#g++ test.cpp  -o ${APP}.exe -lgtest -lpthread
