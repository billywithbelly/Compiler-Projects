ccflags-y := -std=gnu99
scanner: scanner.l
	flex scanner.l
	gcc lex.yy.c -o scanner

clean:
	rm -f scanner *.txt lex.yy.c output.out error.out
