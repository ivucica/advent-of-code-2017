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

