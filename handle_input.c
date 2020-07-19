#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_filename(int argc, char** argv, char* filename) {
  for (int i = 1; i < argc; i++)
    if (argv[i][0] != '-') strcpy(filename, argv[i]);
}

// flags = 1: -w, 2: -s, 4: -g, 8: -r, 16: -y
int get_flags(int argc, char** argv) {
  int flags = 0;

  for (int i = 1; i < argc; i++)
    if (argv[i][0] == '-')
      for (char* letter = &argv[i][1]; *letter != 0; letter++)
        flags += *letter == 'w' && !(flags & 1 << 0) ? 1:
                 *letter == 's' && !(flags & 1 << 1) ? 2:
                 *letter == 'y' && !(flags & 1 << 2) ? 4:
                 *letter == 'g' && !(flags & 1 << 3) ? 8:
                 *letter == 'r' && !(flags & 1 << 4) ? 16:
                 0;

  return flags;
}

char* get_file(char* filename) {
  FILE* file = fopen(filename, "r");

  fseek(file, 0L, SEEK_END);
  long numbytes = ftell(file);
  fseek(file, 0L, SEEK_SET);

  char* contents = (char*)calloc(numbytes, sizeof(char));
  fread(contents, sizeof(char), numbytes, file);

  fclose(file);

  return contents;
}
