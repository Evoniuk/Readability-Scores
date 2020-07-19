# Readability Scores

This program calculates (or more accurately, approximates) the Flesch reading ease and Flesch-Kinkaid grade level of the text supplied to it.

The Flesch reading ease is a measure of how readable a peice of text is, as a function of the number of words, syllables, and sentences it has. In general, the longer the words and the longer the sentences the more difficult the text is considered.

The Flesch-Kinkaid grade level attempts to measure how appropriate a peice of text is for a given grade level in school. It is inversely related with the Flesch reading ease: the higher the reading ease, the lower the grade level.

These measure are not without their flaws. One that comes to mind is that there are many long words (in terms of syllables) that are nonetheless basic ('especially', 'combination', 'immediately', 'communicate'), at the same time as there are many short words that are more advanced ('terse', 'abject', 'cleave', 'inane'). This would cause a sentence like

> Especially interesting is the combination of immediately charming people and the opportunity to communicate.

To score a much lower readability than

> While I cleave to this inane life, an abject hatred arises in me for my terse existence.

The first sentence has an ease of -18.9 and a grade of 19.37. The second has an ease of 70.1 and a grade of 7.7.

Despite their shortcomings, however, these measures are decent heuristics for length texts.
