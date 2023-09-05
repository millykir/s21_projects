CC = gcc
FLAG_C = -c
FLAG_O = -o
FLAG_COV = --coverage 
FLAG_ER = -Wall -Werror -Wextra -std=c11
s21_STRING_C = s21_*.c 
s21_STRING_O = s21_*.o
TEST_CASES_C = test_*.c
TEST_CASES_O = test_*.o
OS := $(shell uname -s)

all: clean s21_string.a test gcov_report

# --- СОЗДАНИЕ БИБЛИОТЕКИ ФУНКЦИЙ ---
s21_string.a:
	$(CC) $(FLAG_C) $(s21_STRING_C) 
	ar rc s21_string.a $(s21_STRING_O)
	ranlib s21_string.a

# --- СОЗДАНИЕ БИБЛИОТЕКИ ТЕСТОВ И ИСПОЛНЕНИЕ ---
test: clean s21_string.a
	$(CC) $(FLAG_C)  $(TEST_CASES_C) main.c
	ar rc test_cases.a $(TEST_CASES_O)
	ranlib test_cases.a

ifeq ($(OS),Linux)
	$(CC) $(FLAG_COV) $(FLAG_O) tests *.c -lcheck -lsubunit -pthread -lrt -lm
endif

ifeq ($(OS),Darwin)
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_string.a test_cases.a $(s21_STRING_C) main.o -lcheck
endif
	./tests

# --- ФОРМИРОВАНИЕ ОТЧЕТА О ПОКРЫТИИ ---
gcov_report: clean test
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o ./report s21_string.info
	open ./report/index.html

check: test 
ifeq ($(OS),Darwin)
	leaks -atExit -- ./tests
endif
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.c *.h
ifeq ($(OS),Linux)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests
endif
	
clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg 
	-rm -f tests
	-rm -rf report