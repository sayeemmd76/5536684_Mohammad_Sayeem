# target name : dependencies
# <tab> commands to generate target

object.o : *.c
	gcc *.c -c

all : *.o
	gcc *.o -o all.out

run : all
	./all.out

clean :
	rm -rf *.o *.out