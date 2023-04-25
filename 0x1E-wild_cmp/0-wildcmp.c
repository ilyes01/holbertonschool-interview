#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if they can be considered
 * identical, otherwise return 0.
 * @s1: the first string to be compared
 * @s2: the second string to be compared. It can contain the special character *
 *
 * Return: 1 if s1 and s2 are considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp(s1, s2 + 1));

		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}

	return (0);
}
