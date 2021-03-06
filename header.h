#ifndef HEADER_FILE
#define HEADER_FILE

// handle flags
int   get_flags(int argc, char** argv);

// statistics
int   word_count(char* string);
int   sentence_count(char* string);
int   syllable_count(char* string);
float readability_score(int words, int sentences, int syllables);
float grade_level(int words, int sentences, int syllables);

// output
void output(int words, int sentences, int syllables, int flags);

#endif
