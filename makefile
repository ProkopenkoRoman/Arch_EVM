all: mySimpleComputer.o myTerm.o myBigChars.o main.o interface.o
	gcc -o main obj/mySimpleComputer.o obj/myTerm.o obj/myBigChars.o obj/interface.o obj/main.o 

mySimpleComputer.o: lab2/mySimpleComputer.c
	gcc -o obj/mySimpleComputer.o -c lab2/mySimpleComputer.c

myTerm.o: lab3/myTerm.c
	gcc -o obj/myTerm.o  -c lab3/myTerm.c

myBigChars.o: lab4/myBigChars.c
	gcc -o obj/myBigChars.o -c lab4/myBigChars.c

interface.o: interface.c
	gcc -o obj/interface.o -c interface.c

main.o: main.c
	gcc -o obj/main.o -c main.c
