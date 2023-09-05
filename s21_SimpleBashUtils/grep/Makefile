FLAGS = -Wall -Werror -Wextra 

all: s21_grep test

s21_grep: s21_grep.c
	gcc s21_grep.c $(FLAGS) -o s21_grep

test: s21_grep.c test.sh
	gcc s21_grep.c $(FLAGS) -o s21_grep && sh test.sh

clean:
	rm -rf *.out s21_grep