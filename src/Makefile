main.exe : main.o intersections.o vectormath.o mymath.o
	gcc -o ../main.exe main.o raytracing.o intersections.o objects.c lights.c vectormath.o mymath.o -luser32 -lgdi32

main.o : main.c
	gcc -ansi -pedantic-errors -Wall -c main.c

raytracing.o : raytracing.c
	gcc -ansi -pedantic-errors -Wall -c raytracing.c

intersections.o : intersections.c
	gcc -ansi -pedantic-errors -Wall -c intersections.c

objects.o : objects.c
	gcc -ansi -pedantic-errors -Wall -c objects.c

lights.o : lights.c
	gcc -ansi -pedantic-errors -Wall -c lights.c

vectormath.o : vectormath.c
	gcc -ansi -pedantic-errors -Wall -c vectormath.c

mymath.o : mymath.c
	gcc -ansi -pedantic-errors -Wall -c mymath.c

clean:
	rm *.o
