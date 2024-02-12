CC = gcc
CFLAG = -Wall -Wextra -Werror -std=c11
CHECKFLAGS = -lcheck -coverage -pthread 
APP = build/Super_super_smart.app

all: install s21_calc.a test gcov_report

install:
	mkdir build
	cd ./build/ && qmake ../Super_super_smart && make all
	@mkdir $(HOME)/Desktop/Calc_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/Calc_v1.0/
	make clean

uninstall:
	@rm -rf build
	@rm -rf $(HOME)/Desktop/Calc_v1.0/

dvi:
	open dvi.html

check:
	checkmk tests.check > s21_test.c

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	make clean
	cp * Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/

s21_calc.a:
	$(CC) $(CFLAG) -c s21_calc.c
	@ar rcs s21_calc.a s21_calc.o
	ranlib s21_calc.a
	rm -rf *.o

test: check
	$(CC) $(CFLAG) *.c $(CHECKFLAGS) -lm
	./a.out

gcov_report: test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml --ignore-errors unmapped -o report s21_test.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.out *.h.gch

	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test s21_test.c
	rm -rf ./build*

lint:
	clang-format -i *.c *.h 

rebuild: clean all