CFLAGS = -g -pedantic-errors -Wall -std=c11

main.exe : main.o raytracing.o intersections.o objectloading.o objects.o lights.o vectormath.o mymath.o
	gcc -g -o ../main.exe main.o raytracing.o intersections.o objectloading.o objects.o lights.o vectormath.o mymath.o -luser32 -lgdi32

main.o : main.c
	gcc $(CFLAGS) -c main.c

raytracing.o : raytracing.c
	gcc $(CFLAGS) -c raytracing.c

intersections.o : intersections.c
	gcc $(CFLAGS) -c intersections.c

objectloading.o : objectloading.c
	gcc $(CFLAGS) -c objectloading.c

objects.o : objects.c
	gcc $(CFLAGS) -c objects.c

lights.o : lights.c
	gcc $(CFLAGS) -c lights.c

vectormath.o : vectormath.c
	gcc $(CFLAGS) -c vectormath.c

mymath.o : mymath.c
	gcc $(CFLAGS) -c mymath.c

clean:
	rm *.o
	rm *.c~
	rm *.h~
	rm *.un~
