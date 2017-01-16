all: clean comp run

clean:
	rm -rf ./*.exe ./*~

comp:
	g++  -std=c++11  -Wall -o redundant.exe  redundant.cpp

run:
	./redundant.exe < input
