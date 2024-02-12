#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>

#define D_SIZE 96
#define SIGN_IN_INT 2147483648

#define TRUE 0
#define FALSE 1

#define NO_USE_BIT_3_ARRAY 2164195328
#define S21_INF 1.0 / 0.0
#define S21_MINUS_INF log(0)
#define S21_NAN 0.0 / 0.0

#define OK_DEC 0
#define S21_INF_DEC 1
#define S21_NEG_INF_DEC 2
#define S21_NAN_DEC 3

#define YES 1
#define NO 0

#define SIZE_INT 32
#define ONE_UINT 1U

#define SCALE_OR_SIGN 3
#define TWO_ARRAY 2
#define ONE_ARRAY 1
#define ZERO_ARRAY 0

#define FIVE_ARRAY_MAX 192
#define TWO_ARRAY_MAX 95
#define ONE_ARRAY_MAX 63
#define ZERO_ARRAY_MAX 31

#define OK_RET 0
#define INF_RET 1
#define NEG_INF_RET 2
#define NAN_RET 3

#define EXP_SHIFT 16
#define EXP_MAX 28
#define EXP_START 112
#define EXP_END 120
#define EXP_MAX_BIT 5
#define EXP_MIN 5
#define MAX_EXP_SIZE 255

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
} s21_big_decimal;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

unsigned int map_array(int bit_map);                                  //
unsigned int shift_one_bit(int bit_map);                              //
int get_bit(s21_decimal *current, int bit_map);                       //
void set_bit(s21_decimal *current, int bit_map);                      //
void unset_bit(s21_decimal *current, int bit_map);                    //
int get_bit_int(int current, int bit_map);                            //
int get_sign(s21_decimal *current);                                   //
void set_sign(s21_decimal *current);                                  //
int set_exp(int exp, s21_decimal *current);                           //
int get_exp(s21_decimal *current);                                    //
s21_decimal get_power_of_ten(int exp);                                //
int get_decimal_zero(s21_decimal current);                            //
void clear(s21_decimal *current);                                     //
s21_decimal no_sign(s21_decimal *current);                            //
void copy(s21_decimal *current1, s21_decimal *current2);              //
void new_set_exp(s21_decimal *current, int exp);                      //
void mul_ten(s21_decimal *current, int exp);                          //
void upper_scale(s21_decimal *current);                               //
void lower_scale(s21_decimal *current);                               //
void same_scale(s21_decimal *current1, s21_decimal *current2);        //
s21_decimal div_no_scale(s21_decimal dividend, s21_decimal divisor);  //
void shift_left(s21_decimal *current);                                //
int add_major(s21_decimal value_1, s21_decimal value_2,
              s21_decimal *result);                        //
s21_decimal reverse(s21_decimal current);                  //
s21_decimal equate(s21_decimal current);                   //
s21_decimal division_by_ten_integer(s21_decimal current);  //
int hight_bit(s21_decimal *current);                       //

int convert_to_dec_fin(s21_big_decimal current, s21_decimal *result,
                       int scale_result, int sign1, int sign2);     //
void clear_big(s21_big_decimal *current);                           //
int get_bit_big(s21_big_decimal current, int bit_map);              //
void set_bit_big(s21_big_decimal *current, int bit_map);            //
void dec_to_big(s21_big_decimal *current1, s21_decimal *current2);  //
void big_to_dec(s21_decimal *current1, s21_big_decimal *current2);  //
s21_big_decimal sum_big_decimal(s21_big_decimal current1,
                                s21_big_decimal current2);            //
void shift_left_big(s21_big_decimal *current);                        //
void shift_right_big(s21_big_decimal *current);                       //
void copy_big(s21_big_decimal *current1, s21_big_decimal *current2);  //
s21_big_decimal division_big_on_ten(s21_big_decimal current);         //
int greater_or_equal_big(s21_big_decimal current1,
                         s21_big_decimal current2);     //
void big_reverse(s21_big_decimal *current);             //
int big_to_dec_exp(s21_big_decimal *current, int exp);  //
void mul_ten_big(s21_big_decimal *current);             //
int scale_norm_big(s21_big_decimal *current1, s21_big_decimal *current2,
                   int exp1, int exp2);                                       //
int equal_big(s21_big_decimal current1, s21_big_decimal current2);            //
int not_equal_big(s21_big_decimal value1, s21_big_decimal value2);            //
int less_big(s21_big_decimal value1, s21_big_decimal value2);                 //
s21_big_decimal sub_big(s21_big_decimal current1, s21_big_decimal current2);  //
void div_big_on_int(s21_big_decimal *res_big, s21_big_decimal *current1,
                    s21_big_decimal *current2, s21_big_decimal tmp,
                    s21_big_decimal tmp_current2);  //

static const char *const powers_ten_exp[29] = {
    [0] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000001",
    [1] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000001010",
    [2] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000001100100",
    [3] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000001111101000",
    [4] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000010011100010000",
    [5] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000011000011010100000",
    [6] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00000011110100001001000000",
    [7] =
        "0000000000000000000000000000000000000000000000000000000000000000000000"
        "00100110001001011010000000",
    [8] =
        "0000000000000000000000000000000000000000000000000000000000000000000001"
        "01111101011110000100000000",
    [9] =
        "0000000000000000000000000000000000000000000000000000000000000000001110"
        "11100110101100101000000000",
    [10] =
        "0000000000000000000000000000000000000000000000000000000000000010010101"
        "00000010111110010000000000",
    [11] =
        "0000000000000000000000000000000000000000000000000000000000010111010010"
        "00011101101110100000000000",
    [12] =
        "0000000000000000000000000000000000000000000000000000000011101000110101"
        "00101001010001000000000000",
    [13] =
        "0000000000000000000000000000000000000000000000000000100100011000010011"
        "10011100101010000000000000",
    [14] =
        "0000000000000000000000000000000000000000000000000101101011110011000100"
        "00011110100100000000000000",
    [15] =
        "0000000000000000000000000000000000000000000000111000110101111110101001"
        "00110001101000000000000000",
    [16] =
        "0000000000000000000000000000000000000000001000111000011011110010011011"
        "11110000010000000000000000",
    [17] =
        "0000000000000000000000000000000000000001011000110100010101111000010111"
        "01100010100000000000000000",
    [18] =
        "0000000000000000000000000000000000001101111000001011011010110011101001"
        "11011001000000000000000000",
    [19] =
        "0000000000000000000000000000000010001010110001110010001100000100100010"
        "01111010000000000000000000",
    [20] =
        "0000000000000000000000000000010101101011110001110101111000101101011000"
        "11000100000000000000000000",
    [21] =
        "0000000000000000000000000011011000110101110010011010110111000101110111"
        "10101000000000000000000000",
    [22] =
        "0000000000000000000000100001111000011001111000001100100110111010101100"
        "10010000000000000000000000",
    [23] =
        "0000000000000000000101010010110100000010110001111110000101001010111101"
        "10100000000000000000000000",
    [24] =
        "0000000000000000110100111100001000011011110011101100110011101101101000"
        "01000000000000000000000000",
    [25] =
        "0000000000001000010001011001010100010110000101000000000101001000010010"
        "10000000000000000000000000",
    [26] =
        "0000000001010010101101111101001011011100110010000000110011010010111001"
        "00000000000000000000000000",
    [27] =
        "0000001100111011001011100011110010011111110100001000000000111100111010"
        "00000000000000000000000000",
    [28] =
        "0010000001001111110011100101111000111110001001010000001001100001000100"
        "00000000000000000000000000",
};

#endif  // S21_DECIMAL_H_
