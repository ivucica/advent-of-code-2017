# ivucica's Advent of Code 2017

I might not complete the advent, but first day seems simple enough.

I've chosen to compile and test the puzzles using [Bazel](https://bazel.build). For instance, to test or run day 1:

```
# test
bazel test //day1:day1_test
# run is done in two steps, as input is fed on standard input
bazel build //day1:day1
"$(bazel info bazel-bin)"/day1/day1 <<< PUZZLE_INPUT
```

I expect to be varying the tools to write solutions.
