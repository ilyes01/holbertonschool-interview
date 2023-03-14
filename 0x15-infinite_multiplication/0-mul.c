#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_error - Print an error message and exit with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - Multiply two positive numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry = 0, sum;
	int *result;

	while (num1[len1])
	{
		if (!_isdigit(num1[len1]))
			print_error();
		len1++;
	}

	while (num2[len2])
	{
		if (!_isdigit(num2[len2]))
			print_error();
		len2++;
	}

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}

	i = 0;
	while (i < len1 + len2 - 1 && result[i] == 0)
		i++;
	while (i < len1 + len2)
		printf("%d", result[i++]);
	printf("\n");
	free(result);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
