#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "diff_for_line.h"

int
main(argc, argv)
char ** argv;
{
  char *line = NULL;
  size_t sz_in = 0;
  ssize_t sz = 0;
  int sum = 0;
  while ((sz = getline(&line, &sz_in, stdin)) != -1)
    {
      sum += diff_for_line(line, sz);
      free(line);
      line = NULL;
      sz_in = 0;
    }
  printf("%d\n", sum);
  return 0;
}
