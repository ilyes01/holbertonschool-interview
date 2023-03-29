#include "holberton.h"
#include <stdio.h>
/**
 * wildcmp - compares two strings and returns 1 if they can be considered identical
 * @s1: the first string
 * @s2: the second string, which can contain the special character '*'
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		/* skip consecutive '*' characters in s2 */
		while (*s2 == '*')
			s2++;

		/* check if s2 is just '*' */
		if (*s2 == '\0')
			return 1;

		/* find the next matching character in s1 after the '*' in s2 */
		while (*s1)
		{
			if (wildcmp(s1, s2))
				return 1;
			s1++;
		}
	}
	else if (*s1 != '\0' && *s2 != '\0')
	{
		/* check if the characters match and recursively check the rest of the strings */
		if (*s1 == *s2 || *s2 == '?')
			return wildcmp(s1 + 1, s2 + 1);
	}
	else
	{
		/* check if both strings are at the end */
		return (*s1 == *s2);
	}

	return 0;
}

