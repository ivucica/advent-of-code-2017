# Day 2: Corruption Checksum

## Disclaimer

Please solve for yourself. I'm posting my own solution for amusement purposes only.

## Solution description

I've stuck to `getline()` and C after the first day. Python would have probably been more appropriate here, but less fun, too.

Since each line has a separate value to be evaluated (maximum, minimum and the actual result -- difference between maximum and minimum), I've opted to move that to a separate function.

I've also opted to move that to a separate file for testability. Code that can be tested should be moved to a separate module (whether we're talking Go, Python or C). In this case, one module is enough. It's even silly; it contains only one function.

Then the test can be written. By convention, `name_of_module.c` is tested with `name_of_module_test.c`. So the actual target `:day2` ends up depending on `:diff_of_line` library, as does the `:diff_of_line_test` target.

I'm sure splitting into items can be done more cleanly than I've done it, but it's still simple: a helper pointer `char *p` points to the beginning of the line. Each time the code runs into a delimiter character, the delimiter is replaced by a NUL-terminator. `value` is extracted with a `sscanf()` on the `p`, and `p` is advanced to one character after the delimiter we replaced with a NUL-terminator.

Minimum and maximum values are initialized to maximum and minimum int respectively. Finding minimum and maximum is a trivial, primary-school-level operation at this point.

Difference is returned, and all the differences are summed (primary-school-style) in the `main()` in `day2.c`.

`diff_for_line_test.c` is a test written in C, while `day2.c` is covered by a bash test like in day 1 puzzle, `day2_test.h`.

### Part 2

TBD

## Problem text

[Solve for yourself](http://adventofcode.com/2017/day/2)

> As you walk through the door, a glowing humanoid shape yells in your direction. "You there! Your state appears to be idle. Come help us repair the corruption in this spreadsheet - if we take another millisecond, we'll have to display an hourglass cursor!"
>
> The spreadsheet consists of rows of apparently-random numbers. To make sure the recovery process is on the right track, they need you to calculate the spreadsheet's *checksum*. For each row, determine the difference between the largest value and the smallest value; the checksum is the sum of all of these differences.
>
> For example, given the following spreadsheet:
>
> ```
> 5 1 9 5
> 7 5 3
> 2 4 6 8
> ```
>
> - The first row's largest and smallest values are `9` and `1`, and their difference is `8`.
> - The second row's largest and smallest values are `7` and `3`, and their difference is `4`.
> - The third row's difference is `6`.
>
> In this example, the spreadsheet's checksum would be `8 + 4 + 6 = 18`.
>
> *What is the checksum* for the spreadsheet in your puzzle input?

### Part 2

> "Great work; looks like we're on the right track after all. Here's a *star* for your effort." However, the program seems a little worried. Can programs be worried?
>
> "Based on what we're seeing, it looks like all the User wanted is some information about the *evenly divisible values* in the spreadsheet. Unfortunately, none of us are equipped for that kind of calculation - most of us specialize in bitwise operations."
>
> It sounds like the goal is to find the only two numbers in each row where one evenly divides the other - that is, where the result of the division operation is a whole number. They would like you to find those numbers on each line, divide them, and add up each line's result.
>
> For example, given the following spreadsheet:
>
> ```
> 5 9 2 8
> 9 4 7 3
> 3 8 6 5
> ```
>
> * In the first row, the only two numbers that evenly divide are `8` and `2`; the result of this division is `4`.
> * In the second row, the two numbers are `9` and `3`; the result is `3`.
> * In the third row, the result is `2`.
>
> In this example, the sum of the results would be `4 + 3 + 2 = 9`.
>
> What is the *sum of each row's result* in your puzzle input?


