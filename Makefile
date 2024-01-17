raytracer.exe : raytracer.o
	g++ -o raytracer.exe raytracer.o

raytracer.o : raytracer.cpp
	g++ -ansi -pedantic-errors -Wall -c raytracer.cpp

clean:
	rm edit raytracer.o
