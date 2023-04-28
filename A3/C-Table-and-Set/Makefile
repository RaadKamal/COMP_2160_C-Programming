all: Set Set1 Set2 Set3 Set4


Set:main.c set.h set.o
	clang -Wall main.c set.o -o Set

Set1:main.c set.h set1.o
	clang -Wall main.c set1.o -o Set1
	
Set2:main.c set.h set2.o
	clang -Wall main.c set2.o -o Set2

Set3:main.c set.h set3.o
	clang -Wall main.c set3.o -o Set3

Set4:main.c set.h set4.o
	clang -Wall main.c set4.o -o Set4

clean:
	rm -f set.o set1.o set2.o set3.o set4.o Set Set1 Set2 Set3 Set4         
