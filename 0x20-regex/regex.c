#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*') {
		if (regex_match(str, pattern + 2))
			return (1);

		while (*str != '\0' && (*str == *pattern || *pattern == '.')) {
			if (regex_match(++str, pattern + 2))
				return (1);
		}
		return (0);
	}

	if (*str == '\0')
		return (0);

	if (*str == *pattern || *pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
