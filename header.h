#ifndef HEADER_FILE
#define HEADER_FILE

// handle input
void  get_filename(int argc, char** argv, char* filename);
int   get_flags(int argc, char** argv);
char* get_file(char* filename);

// statistics
int   word_count(char* string);
int   sentence_count(char* string);
int   syllable_count(char* string);
float readability_score(int words, int sentences, int syllables);
float grade_level(int words, int sentences, int syllables);

// output
void output(int words, int sentences, int syllables, int flags);

#endif
