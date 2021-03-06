#include <stdio.h>

#include "./header.h"

// flags = 1: -w, 2: -s, 4: -g, 8: -r, 16: -y
void output(int words, int sentences, int syllables, int flags) {
  if (1 << 0 & flags) printf("Words: %d\n", words);
  if (1 << 1 & flags) printf("Sentences: %d\n", sentences);
  if (1 << 2 & flags) printf("Syllables: %d\n", syllables);
  if (1 << 3 & flags) printf("Grade Level: %f\n", grade_level(words, sentences, syllables));
  if (1 << 4 & flags) printf("Readability Score: %f\n", readability_score(words, sentences, syllables));
}
