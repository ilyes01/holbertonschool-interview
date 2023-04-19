#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int slen = strlen(s);
    int wlen = strlen(words[0]);
    int total_len = nb_words * wlen;
    int *freq = calloc(nb_words, sizeof(int));
    int *indices = malloc(slen * sizeof(int));
    int i, j, k, start, count, match;
    *n = 0;

    for (i = 0; i <= slen - total_len; i++) {
        memset(freq, 0, nb_words * sizeof(int));
        count = 0;
        for (j = 0; j < nb_words; j++) {
            start = i + j * wlen;
            match = 0;
            for (k = 0; k < wlen; k++) {
                if (s[start + k] != words[j][k]) {
                    break;
                }
                match++;
            }
            if (match == wlen) {
                freq[j]++;
                count++;
            }
        }
        if (count == nb_words) {
            indices[*n] = i;
            (*n)++;
        } else {
            for (j = 0; j < nb_words; j++) {
                freq[j] = 0;
            }
        }
    }

    free(freq);
    if (*n == 0) {
        free(indices);
        indices = NULL;
    }
    return indices;
}

