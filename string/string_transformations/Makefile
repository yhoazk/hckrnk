all: clean comp run

clean:
	rm -rf ./*.exe ./*~

comp:
	g++ -Wall -o string_transformations.exe  string_transformations.cpp

run:
	./string_transformations.exe < input
