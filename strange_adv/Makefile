all: clean comp run

clean:
	rm -rf ./*.exe

comp:
	g++ -g -Wall -o strange_adv.exe strange_adv.cpp

run:
	./strange_adv.exe < input
