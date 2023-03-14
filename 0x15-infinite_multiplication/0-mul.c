#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error_and_exit() {
  printf("Error\n");
  exit(98);
}

void print_result(char *result) {
  printf("%s\n", result);
}

int is_digit(char c) {
  return c >= '0' && c <= '9';
}

int parse_num(char *str, int *digits) {
  int len = strlen(str);
  int i;
  for (i = 0; i < len; i++) {
    if (!is_digit(str[i])) {
      print_error_and_exit();
    }
    digits[i] = str[len - 1 - i] - '0';
  }
  return len;
}

void multiply(int *a, int alen, int *b, int blen, int *result) {
  int i, j;
  for (i = 0; i < alen; i++) {
    for (j = 0; j < blen; j++) {
      result[i+j] += a[i] * b[j];
      result[i+j+1] += result[i+j] / 10;
      result[i+j] %= 10;
    }
  }
}

void format_result(int *result, int len, char *str) {
  int i;
  for (i = 0; i < len; i++) {
    str[len - 1 - i] = result[i] + '0';
  }
  str[len] = '\0';
}

int main(int argc, char **argv) {
  if (argc != 3) {
    print_error_and_exit();
  }

  int num1_digits[1000], num2_digits[1000];
  int num1_len = parse_num(argv[1], num1_digits);
  int num2_len = parse_num(argv[2], num2_digits);

  int result[2000] = {0};
  multiply(num1_digits, num1_len, num2_digits, num2_len, result);

  char result_str[2001];
  format_result(result, num1_len + num2_len, result_str);

  print_result(result_str);

  return 0;
}
