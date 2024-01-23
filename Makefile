main.exe : main.o
	gcc -o main.exe main.o -luser32 -lgdi32

main.o : main.c
	gcc -ansi -pedantic-errors -Wall -c main.c
