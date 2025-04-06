all: main.exe

main.exe: main.cpp clases.cpp 
	g++ -o main.exe main.cpp clases.cpp 

run: main.exe
	./main.exe
	rm -f main.exe


clean:
	rm -f main.exe
