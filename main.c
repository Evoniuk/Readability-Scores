// this program calculates the Flesch Reading Ease score and the Flesch–Kincaid grade level
// of text supplied in the file given as input. The possible flags are w, s, y, g, and r:
// w: word count
// s: sentence count
// y: syllable count
// g: grade level
// r: reading level

#include <stdlib.h>
#include "./header.h"

#define MAX_FILE_L 32

int main(int argc, char** argv) {
  char filename[MAX_FILE_L];
  get_filename(argc, argv, filename);

  int flags = get_flags(argc, argv);

  char* contents = get_file(filename);

  int words     = word_count(contents);
  int sentences = sentence_count(contents);
  int syllables = syllable_count(contents);

  free(contents);

  output(words, sentences, syllables, flags);

  return 0;
}
