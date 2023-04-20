#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of
 * words, within a given string.
 * @s: the string to scan
 * @words: the array of words all substrings must be a concatenation
 * arrangement of
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 * returned array.
 *
 * Return: an allocated array, storing each index in s, at which a substring
 * was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, word_len, remaining, j, i, k;
	int *count, *res;

	if (!s || !words || !*words || !n || nb_words < 1)
		return (NULL);

	len = strlen(s);
	word_len = strlen(words[0]);
	count = calloc(nb_words, sizeof(*count));
	res = malloc(len * sizeof(*res));

	for (i = 0, *n = 0; i <= len - nb_words * word_len; i++)
	{
		remaining = nb_words;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (count[k] == 0 && strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					count[k] = 1;
					remaining--;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (remaining == 0)
			res[(*n)++] = i;
		memset(count, 0, nb_words * sizeof(*count));
	}

	free(count);

	return ((*n) > 0 ? res : NULL);
}

