#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - computes the length of a string
 * @s: the string to measure
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * mul - multiplies two positive numbers
 * @num1: the first number to multiply
 * @num2: the second number to multiply
 *
 * Return: a pointer to the product of num1 and num2
 */
char *mul(char *num1, char *num2)
{
	int len1, len2, i, j, k, carry, n1, n2, sum;
	char *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		exit(98);
	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	result[len1 + len2] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		if (!_isdigit(num1[i]))
		{
			free(result);
			exit(98);
		}
		carry = 0;
		n1 = num1[i] - '0';
		k = len2 + i;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!_isdigit(num2[j]))
			{
				free(result);
				exit(98);
			}
			n2 = num2[j] - '0';
			sum = n1 * n2 + carry + (result[k] - '0');
			carry = sum / 10;
			result[k] = (sum % 10) + '0';
			k--;
		}
		if (carry > 0)
			result[k] = (carry % 10) + '0';
	}
	if (*result == '0' && *(result + 1) != '\0')
		result++;
	return (result);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of command-line arguments
 * @argv: the command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	result = mul(argv[1], argv[2]);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	printf("%s\n", result);
	free(result);
	return (0);
}
