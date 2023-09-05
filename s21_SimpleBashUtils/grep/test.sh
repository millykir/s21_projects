#!/bin/bash

./s21_grep -v s test.txt test_1.txt > 1.txt
grep -v s test.txt test_1.txt > 2.txt
RES="$(diff -s 1.txt 2.txt)"

if [ "$RES" == "Files 1.txt and 2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm 1.txt 2.txt


./s21_grep -e s test.txt > pruf_1.txt
grep -e s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -i s test.txt > pruf_1.txt
grep -i s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -v s test.txt > pruf_1.txt
grep -v s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -c s test.txt > pruf_1.txt
grep -c s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -l s test.txt > pruf_1.txt
grep -l s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -n s test.txt > pruf_1.txt
grep -n s test.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep s test.txt test_1.txt > pruf_1.txt
grep s test.txt test_1.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -e s test.txt test_1.txt > pruf_1.txt
grep -e s test.txt test_1.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep s test.txt test_1.txt test_2.txt > pruf_1.txt
grep s test.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -l dfhs test.txt test_1.txt test_2.txt > pruf_1.txt
grep -l dfhs test.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -h s test_3.txt test_1.txt test_2.txt > pruf_1.txt
grep -h s test_3.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep g test_3.txt test_1.txt test_2.txt > pruf_1.txt
grep g test_3.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep s test_3.txt test_1.txt test_2.txt > pruf_1.txt
grep s test_3.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -f f.txt test_1.txt test_2.txt > pruf_1.txt
grep -f f.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt

./s21_grep -v s  test_2.txt > pruf_1.txt
grep -v s test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt

./s21_grep -c s  test_2.txt > pruf_1.txt
grep -c s test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt

./s21_grep -in s f.txt test_1.txt test_2.txt > pruf_1.txt
grep -in s f.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -cv s f.txt test_1.txt test_2.txt > pruf_1.txt
grep -cv s f.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt

./s21_grep -lv s f.txt test_1.txt test_2.txt > pruf_1.txt
grep -lv s f.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt


./s21_grep -o s f.txt test_1.txt test_2.txt > pruf_1.txt
grep -o s f.txt test_1.txt test_2.txt > pruf_2.txt
RES="$(diff -s pruf_1.txt pruf_2.txt)"

if [ "$RES" == "Files pruf_1.txt and pruf_2.txt are identical" ]
then
echo "SUCCESS"
else
echo "FAIL"
fi
rm pruf_1.txt pruf_2.txt



