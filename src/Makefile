main.exe : main.o raytracing.o intersections.o objectloading.o objects.o lights.o vectormath.o mymath.o
	gcc -g -o ../main.exe main.o raytracing.o intersections.o objectloading.o objects.o lights.o vectormath.o mymath.o -luser32 -lgdi32

main.o : main.c
	gcc -g -pedantic-errors -Wall -c main.c

raytracing.o : raytracing.c
	gcc -g -pedantic-errors -Wall -c raytracing.c

intersections.o : intersections.c
	gcc -g -pedantic-errors -Wall -c intersections.c

objectloading.o : objectloading.c
	gcc -g -pedantic-errors -Wall -c objectloading.c

objects.o : objects.c
	gcc -g -pedantic-errors -Wall -c objects.c

lights.o : lights.c
	gcc -g -pedantic-errors -Wall -c lights.c

vectormath.o : vectormath.c
	gcc -g -pedantic-errors -Wall -c vectormath.c

mymath.o : mymath.c
	gcc -g -pedantic-errors -Wall -c mymath.c

clean:
	rm *.o
