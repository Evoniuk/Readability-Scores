int is_word_delimeter(char character);
int is_vowel(char character);
int is_sentence_delimeter(char character);

int word_count(char* string) {
  int result = 0;
  for (char* character = string; *character != 0; character++) {
    if (is_word_delimeter(*character)) {
      result++;
      while (is_word_delimeter(*(character + 1))) 
        character++;
    }
  }

  return result;
}

int syllable_count(char* string) {
  int result = 0;
  for (char* character = string; *character != 0; character++) {
    if (is_vowel(*character)) {
      result++;
      while (is_vowel(*(character + 1))) character++;
    }
  }

  return result;
}

int sentence_count(char* string) {
  int result = 0;
  for (char* character = string; *character != 0; character++)
    if (is_sentence_delimeter(*character)) {
      result++;
      while (is_sentence_delimeter(*(character + 1))) character++;
    }

  return result;
}

float readability_score(int words, int sentences, int syllables) {
  return 206.835 - 1.015*((float) words / sentences) - 84.6*((float) syllables / words);
}

float grade_level(int words, int sentences, int syllables) {
  return .39*((float) words / sentences) + 11.8*((float) syllables / words) - 15.59;
}

// helpers:

int is_word_delimeter(char character) {
  return character == ' ' ||
         character == '.' ||
         character == '-'  ? 1 : 0;
}

int is_vowel(char character) {
  return character == 'a' ||
         character == 'e' ||
         character == 'i' ||
         character == 'o' ||
         character == 'u' ? 1 : 0;
}

int is_sentence_delimeter(char character) {
  return character == '.' ||
         character == '!' ||
         character == '?' ? 1 : 0;
}
