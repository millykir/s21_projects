FLAGS = -Wall -Werror -Wextra 

all: s21_cat test

s21_cat: s21_cat.c
	gcc s21_cat.c $(FLAGS) -o s21_cat

test: s21_cat.c tests.sh
	gcc s21_cat.c $(FLAGS) -o s21_cat && sh tests.sh

clean:
	rm -rf *.out s21_cat s21_cat