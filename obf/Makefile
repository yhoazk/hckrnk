APP=toasci

all: clean prepare comp run 

clean:
	rm -rf ${APP}.exe *.rgb 


prepare:
	convert -geometry 80x cmeng.png cmeng.rgb


comp:
	gcc -pedantic -o ${APP}.exe ${APP}.c

run:
	cat cmeng.rgb | ./${APP}.exe 
