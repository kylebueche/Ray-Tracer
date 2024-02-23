main.exe : main.o intersections.o vectormath.o mymath.o
	gcc -o ../main.exe main.o intersections.o vectormath.o mymath.o -luser32 -lgdi32

main.o : main.c
	gcc -ansi -pedantic-errors -Wall -c main.c

intersections.o : intersections.c
	gcc -ansi -pedantic-errors -Wall -c intersections.c

vectormath.o : vectormath.c
	gcc -ansi -pedantic-errors -Wall -c vectormath.c

mymath.o : mymath.c
	gcc -ansi -pedantic-errors -Wall -c mymath.c

clean:
	rm *.o
