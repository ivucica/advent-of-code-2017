#include <stdio.h>
#include <limits.h>
#include "diff_for_line.h"

int diff_for_line(line, sz)
char * line;
size_t sz;
{
  int min = INT_MAX;
  int max = INT_MIN;

  char *p = line;
  for(int i = 0; i < sz; i++)
    {
      if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
          int value = 0;
          line[i] = 0;
          sscanf(p, "%d", &value);
          p = line + i + 1;

          if (value < min)
            min = value;
          if (value > max)
            max = value;
        }
    }
  return max - min;
}
