objects = arodriguez_prog2.o arodriguez_argtok.o arodriguez_exec.o \



arodriguez_prog2: $(objects)

	cc -o arodriguez_prog2 $(objects)

arodriguez_prog2.o: arodriguez_prog2.c arodriguez_exec.h arodriguez_argtok.h

	cc -c  arodriguez_prog2.c

clean:

	rm arodriguez_prog2 $(objects)
