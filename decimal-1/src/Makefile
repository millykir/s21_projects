C = converters/*.c comparison/*.c arithmetic/*.c  another/*.c big_decimal/*.c support/*.c
FLAGS = -Wall -Wextra -Werror -std=c11
OS := $(shell uname -s)

all: clean s21_decimal.a test gcov_report

s21_decimal.a: 
	gcc -c $(FLAGS) $(C) -g
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a
	rm -rf *.o

# --- СОЗДАНИЕ БИБЛИОТЕКИ ТЕСТОВ И ИСПОЛНЕНИЕ ---
test: clean s21_decimal.a
	gcc -c tests/*.c -g
	ar rc test_cases.a tests.o
	ranlib test_cases.a

ifeq ($(OS),Linux)
	gcc --coverage -o test.o $(C) tests/tests.c -lcheck -lsubunit -lrt -lm -g -lpthread 
endif

ifeq ($(OS),Darwin)
	gcc $(FLAGS) --coverage -o test.o s21_decimal.a test_cases.a $(C) tests.o -lcheck
endif
	./test.o

rebuild: clean all

s21_div.a: clean
	gcc -o s21_div.a $(C) -lm -g
	./s21_div.a

style:
	clang-format -i *.h converters/*.c comparison/*.c arithmetic/*.c  another/*.c big_decimal/*.c support/*.c tests/*.c

check:
	clang-format -n *.h converters/*.c comparison/*.c arithmetic/*.c  another/*.c big_decimal/*.c support/*.c tests/*.c

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file=valgrind.log ./test.o 

gcov_report:
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
ifeq ($(OS), Darwin)
	open report/index.html
endif
ifeq ($(OS), Linux)
	xdg-open report/index.html
endif

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov 
	rm -rf ./report
