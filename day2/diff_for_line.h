#if !defined(_DIFF_FOR_LINE_H)
#define _DIFF_FOR_LINE_H 1

// Return difference between largest and smallest value in a
// string line of length sz. Numbers must be ASCII-encoded,
// and line must end with a whitespace, a tab character, or
// by a newline otherwise the last value will be ignored.
// Each value must be separated by exactly one tab, whitespace
// or newline.
int
diff_for_line(char * line, size_t sz);

#endif

