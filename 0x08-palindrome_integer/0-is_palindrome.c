#include "palindrome.h"
/**
*is_palindrome - checks whether or not
*@n: check number
*Return:0 or 1
*/
int is_palindrome(unsigned long n)
{
	unsigned long x = n, p;

	for (p = 1; x >= 1; p = p * 10)
		x = x / 10;
	p /= 10;
	while (p > 1)
	{
		if (n / p != n % 10)
			return (0);
		n = (n % p) / 10;
		p = p / 100;
	}
	return (1);
}
