#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_error_and_exit - prints an error message and exits the program
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * print_result - prints a string to stdout followed by a newline character
 * @result: the string to print
 */
void print_result(char *result)
{
	printf("%s\n", result);
}

/**
 * is_digit - determines if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, otherwise 0
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * parse_num - parses a string of digits into an array of integers
 * @str: the string to parse
 * @digits: the array to store the integers in
 *
 * Return: the length of the parsed string
 */
int parse_num(char *str, int *digits)
{
	int len = strlen(str);
	int i;

	for (i = 0; i < len; i++)
	{
		if (!is_digit(str[i]))
		{
			print_error_and_exit();
		}
		digits[i] = str[len - 1 - i] - '0';
	}

	return (len);
}

/**
 * multiply - multiplies two arrays of integers and stores the result
 * @a: the first array of integers
 * @alen: the length of the first array
 * @b: the second array of integers
 * @blen: the length of the second array
 * @result: the array to store the result in
 */
void multiply(int *a, int alen, int *b, int blen, int *result)
{
	int i, j;

	for (i = 0; i < alen; i++)
	{
		for (j = 0; j < blen; j++)
		{
			result[i + j] += a[i] * b[j];
			result[i + j + 1] += result[i + j] / 10;
			result[i + j] %= 10;
		}
	}
}

/**
 * format_result - formats an array of integers as a string
 * @result: the array of integers to format
 * @len: the length of the array
 * @str: the string to store the formatted result in
 */
void format_result(int *result, int len, char *str)
{
	int i;

	for (i = 0; i < len; i++) {
		str[len - 1 - i] = result[i] + '0';
	}

	str[len] = '\0';
}

/**
 * remove_first_char - removes the first character from a string
 * @str: the string to modify
 */
void remove_first_char(char *str)
{
	int len = strlen(str);
	int i;

	for (i = 0; i < len; i++) {
		str[i] = str[i + 1];
	}
}

/**
 * main - entry point of the program
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
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
	remove_first_char(result_str);
	print_result(result_str);

	return 0;
}
