all: main.exe

main.exe: main.cpp Curso.cpp estudiante.cpp 
	g++ -o main.exe main.cpp Curso.cpp estudiante.cpp 

run: main.exe
	./main.exe

clean:
	rm -f main.exe
