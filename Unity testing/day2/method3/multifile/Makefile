# target name : dependencies
# <tab> commands to generate target
scr=*.c
obj=*.o
object.o : $(scr)
	gcc *.c -c

all : $(obj)
	gcc *.o -o all.out

run : all
	./all.out

clean :
	rm -rf *.o *.out