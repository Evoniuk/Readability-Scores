// this program calculates the Flesch Reading Ease score
// and the Flesch–Kincaid grade level of text supplied
// in the file given as input.

// the possible flags are as follows:
// w: word count
// s: sentence count
// y: syllable count
// g: grade level
// r: reading level

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./header.h"

#define MAX_FILE_L 32

static char* read_file(char* filename) {
  FILE* file = fopen(filename, "r");

  fseek(file, 0L, SEEK_END);
  long numbytes = ftell(file);
  fseek(file, 0L, SEEK_SET);

  char* contents = (char*)malloc(numbytes * sizeof(char));
  fread(contents, sizeof(char), numbytes, file);

  fclose(file);

  return contents;
}

static int get_file_index(int argc, char** argv) {
  for (int i = 1; i < argc; i++)
    if (argv[i][0] != '-') return i;

  fprintf(stderr, "Could not find file.");
  exit(74);
}

int main(int argc, char** argv) {
  int file_index = get_file_index(argc, argv);

  int flags = get_flags(argc, argv);

  char* contents = read_file(argv[file_index]);

  int words     = word_count(contents);
  int sentences = sentence_count(contents);
  int syllables = syllable_count(contents);

  free(contents);

  output(words, sentences, syllables, flags);

  return 0;
}
