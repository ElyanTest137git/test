
# this is comments in makefile
# It's terrible to find that in the past two years,
# I completely wrote makefile in a wrong way...
# ---> the target of a rule is a file, rather than a category ...
# more makefile detail: http://www.gnu.org/software/make/manual/make.html

# .PHONY means the targe is actually not a output filename
.PHONY: all
all: sud.exe main.o sudoku.o
	gcc main.o sudoku.o -o sud.exe

sud.exe: main.o sudoku.o
	gcc main.o sudoku.o -o sud.exe

main.o: sudoku.h main.c
	gcc -c main.c

sudoku.o: sudoku.h sudoku.c
	gcc -c sudoku.c


# clean test files yourself~
.PHONY: clean
clean:
	rm -f *.o *.out *.exe

