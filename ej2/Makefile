all: main.exe

main.exe: main.cpp Curso.cpp estudiante.cpp menu.cpp
	g++ -o main.exe main.cpp Curso.cpp estudiante.cpp menu.cpp

run: main.exe
	./main.exe
	rm -f main.exe


clean:
	rm -f main.exe
