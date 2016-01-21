

all: uses_comparisons without_comparisons

uses_comparisons: uses_comparisons.c
	g++ uses_comparisons.c -o uses_comparisons

without_comparisons: without_comparisons.c
	g++ without_comparisons.c -o without_comparisons

clean:
	rm -f uses_comparisons.exe
	rm -f uses_comparisons
	rm -f without_comparisons.exe
	rm -f without_comparisons
