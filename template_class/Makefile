
app_name = template_class

all: clean comp run

clean:
	rm -rf ./${app_name}.exe


comp:
	g++ -Wall -o ${app_name} ${app_name}.cpp

run:
	./${app_name}.exe < input



