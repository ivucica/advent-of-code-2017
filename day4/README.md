# Day 4: High Entropy Passphrases

## Disclaimer

Please solve for yourself. I'm posting my own solution for amusement purposes only.

## Solution description

This problem is perfect for stuff Python is good in, so I chose to use it and figure out how to use it with Bazel. (An interesting issue turned out to be the directory where the main file lives being in Python path, on at least macOS. This meant that `from package.path.here import here_lib` broke down, because all my day-paths are in the root dir. So, `from day4 import day4_lib` broke down because, instead of the directory matching `//day4`, Python tried to import from the main `.py` file for the day, `day4.py`.)

Anyway, the process:

* read lines from stdin
* split each line by spaces
* turn the iterable into a `set()`
* if `len(iterable)` and `len(set)` match, there are no duplicates

Summing is trivial then.

I might try doing this with a `map/reduce` at a later time.

### Part 2

I've elected to modify part 1 code to also accept an argument (including on command line) whether anagrams are banned.

If they are, the list of words in a passphrase is modified using list comprehension to contain words containing sorted arguments. Once this is done, list is turned into set as before, and lengths of lists are compared.

Every anagram of a word will be equal once its characters are sorted.

## Problem text

[Solve for yourself](http://adventofcode.com/2017/day/4)

> A new system policy has been put in place that requires all accounts to use a *passphrase* instead of simply a pass*word*. A passphrase consists of a series of words (lowercase letters) separated by spaces.
>
> To ensure security, a valid passphrase must contain no duplicate words.
>
> For example:
>
> * `aa bb cc dd ee` is valid.
> * `aa bb cc dd aa` is not valid - the word `aa` appears more than once.
> * `aa bb cc dd aaa` is valid - `aa` and `aaa` count as different words.
>
> The system's full passphrase list is available as your puzzle input. *How many passphrases are valid?*

### Part 2

> For added security, yet another system policy has been put in place. Now, a valid passphrase must contain no two words that are anagrams of each other - that is, a passphrase is invalid if any word's letters can be rearranged to form any other word in the passphrase.
>
> For example:
>
> `abcde fghij` is a valid passphrase.
> `abcde xyz ecdab` is not valid - the letters from the third word can be rearranged to form the first word.
> `a ab abc abd abf abj` is a valid passphrase, because *all* letters need to be used when forming another word.
> `iiii oiii ooii oooi oooo` is valid.
> `oiii ioii iioi iiio` is not valid - any of these words can be rearranged to form any other word.
>
> Under this new system policy, *how many passphrases are valid*?
