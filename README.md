# Readability Scores

This program calculates (or more accurately, approximates) the Flesch reading ease and Flesch-Kinkaid grade level of the text supplied to it.

The Flesch reading ease is a measure of how readable a peice of text is, as a function of the number of words, syllables, and sentences it has. In general, the longer the words and the longer the sentences the more difficult the text is considered.

The Flesch-Kinkaid grade level attempts to measure how appropriate a peice of text is for a given grade level in school. It is inversely related with the Flesch reading ease: the higher the reading ease, the lower the grade level.

These measure are not without their flaws. One that comes to mind is that there are many long words (in terms of syllables) that are nonetheless basic ('especially', 'combination', 'immediately', 'communicate'), at the same time as there are many short words that are more advanced ('terse', 'abject', 'cleave', 'inane'). This would cause a sentence like

> Especially interesting is the combination of immediately charming people and the opportunity to communicate.

To score an ease of -18.9 and a grade of 19.37, while

> While I cleave to this inane life, an abject hatred arises in me for my terse existence.

gets an ease of 70.1 and a grade of 7.7.

Despite their shortcomings, however, these measures are decent heuristics for lengthy texts.

## The Interface

The interface of this program is fairly simple. You can simply type

```bash
$ PROGRAM -r FILENAME.txt
```

To see the reading ease of the text contained in `FILENAME.txt`. Here the `-r` flag was selected, which will print the reading ease. The complete list of flags are as follows:

* `-r`: displays reading ease
* `-g`: displays grade
* `-w`: displays word count
* `-s`: displays sentence count
* `-y`: displays syllable count

If no flags are selected nothing will be returned. Flags can be combined as well, so you can have something like

```bash
$ PROGRAM -rgwsy FILENAME.txt
```

If you wish to know all five statistics regarding `FILENAME.txt`.

## The Implementation

The implementation of this program is carried out in four C files:

* `main.c`
* `handle_input.c`
* `stats.c`
* `output.c`

### `main.c`

`main.c` coordinates the process. It receives the input and passes it to the functions in `handle_input.c`, then takes what it receives and gives it to the functions in `stats.c`, takes that output and gives it to `output`, the sole function in `output.c`.

### `handle_input.c`

`handle_input.c` contains three functions:

* `void get_filename(int argc, char** argv, char* filename)`
* `char* get_file(char* filename)`
* `int get_flags(int argc, char** argv)`

Of these `get_flags` is the only one of interest. It is implemented like so:

```C
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
```

As can be seen, the first five binary digits of the `int` return value correspond to the five flags. This plays a role in how `output` works, as will be seen.

### `stats.c`

This file contains the functions that do the calculations. It is also where its clear that some things just have to be estimated when dealing with natural language.

There are three statistics about our file that need to be calculated:

* Word count
* Syllable count
* Sentence count

In each of these cases, the method used is to find characters that are, more or less, equivalent to a word, syllable, or sentence appearing, and then to count the number of occurences of such characters. For words, this is a space, a period, or a '-'. For syllables, the characters to look for would be any of the vowels. And for sentences, they would be a period, an exclamation point, or a question mark.

But simply counting the occurences of each of these symbols does not result in a very accurate count. If we take sentences for example, looking for periods, exclamation points, and question marks would make things like ellipses and '!?!?' impact the count too much. Because of this, whenever we encounter one of these characters when looking for sentences, we skip to the next character that isn't one of these.

What's nice about this method is that it works for counting words and syllables as well: for words, we wouldn't want a dash surrounded by spaces to count as three words, so as soon as we encounter the first space we increment our count and skip to the next character that isn't a dash, space, or period.

For syllables this is less accurate, but it isn't so bad, as consecutive vowels in English almost always denote a single syllable. The real problem with the inaccuracy of the syllable count would be words like 'are', which has one syllable but would be counted as having two, and 'interesting', which (in my dialect of English) has three syllables, but would be counted as having four. Ideally this over- and under-counting would cancel out to some degree, but the fact is that the syllable count will just have to be inaccurate if we don't want to reference a dictionary.

### `output.c`

`output.c` has a single function, `void output(int words, int sentences, int syllables, int flags)`, which takes in the stats of the text and outputs the information that the user wishes to see, based on what flags have been selected.
