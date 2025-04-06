all: main.exe

main.exe: main.cpp implementaciones.cpp 
	g++ -o main.exe main.cpp implementaciones.cpp 

run: main.exe
	./main.exe

clean:
	rm -f main.exe
