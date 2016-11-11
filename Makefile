all: clean comp run

clean:
	rm -rf ./*.exe

comp:
	gcc -g sort_intro.c -o sort_intro.exe
run:
	./sort_intro.exe < input 
