CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LIBS=-lcheck
GFLAGS=-fprofile-arcs -ftest-coverage

all: clean s21_math.a test

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	cp s21_math.a libs21_math.a
	cp s21_math.a ls21_math.a
	ranlib libs21_math.a
	ranlib ls21_math.a

s21_math.o: s21_math.c
	$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o

test: s21_math.a
	$(CC) $(CFLAGS) test.c s21_math.a -o test $(LIBS)
	./test

gcov_report: clean s21_math.a
	$(CC) $(CFLAGS) $(GFLAGS) test.c s21_math.c s21_math.a -o test $(LIBS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
	CK_FORK=no leaks --atExit -- ./test
	make clean

open:
	open report/index.html

rebuild: clean all

clean:
	rm -rf *.gc* *.o *.a *.out *.info test
	rm -rf report