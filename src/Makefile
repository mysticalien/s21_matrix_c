CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -std=c11
LFLAGS = -Wall -Werror -Wextra -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -fanalyzer
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTFLAGS = -lcheck

FILES= $(wildcard s21_*.c)

all: s21_matrix.a

s21_matrix.a: s21_matrix.o
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a
	rm *.o

s21_matrix.o: $(FILES) s21_matrix.h
	$(CC) $(CFLAGS) -c $(FILES)

test: s21_matrix.o
	$(CC) $(CFLAGS) test.c $(FILES) $(TESTFLAGS) -o test

leaks: s21_matrix.a
	clear
	$(CC) $(CFLAGS) test.c s21_matrix.a -o v
	valgrind --tool=memcheck --leak-check=yes ./v
	leaks -atExit -- ./v
	$(CC) $(LFLAGS) test.c s21_matrix.a -o 1
	./1

gcov_report:
	$(CC) $(CFLAGS) test.c $(FILES) $(TESTFLAGS) $(COVFLAGS) -o test
	./test
	lcov -t "Matrix_tests" -o test.info -c -d .
	genhtml -o report test.info
	rm *.gcda *.gcno *.info
	open report/index.html

style:
	clang-format -i -style=Google *.c *.h

clean:
	rm -rf report
	rm -f *.a
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -f test
	rm -rf test.dSYM



.PHONY: all test gcov_report style clean s21_matrix.a


