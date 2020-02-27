arodriguez_prog2 : arodriguez_prog2.o arodriguez_argtok.o arodriguez_exec.o
	cc -o arodriguez_prog2 arodriguez_prog2.o arodriguez_argtok.o arodriguez_exec.o

arodriguez_prog2.o : arodriguez_prog2.c arodriguez_argtok.h arodriguez_exec.h
	cc -c arodriguez_prog2.c

arodriguez_argtok.o: arodriguez_argtok.c arodriguez_argtok.h
	cc -c arodriguez_argtok.c

arodriguez_exec.o: arodriguez_exec.c arodriguez_exec.h
	cc -c arodriguez_exec.c

clean :
	rm arodriguez_prog2 arodriguez_prog2.o arodriguez_argtok.o arodriguez_exec.o
