#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char *line = NULL;
  size_t sz = 0;
  ssize_t ret = getline(&line, &sz, stdin);
  if (ret == -1)
    {
      free(line);
      return 1;
    }

  // strip newline characters
  for (int i = 0; i < ret; i++)
    {
      if (line[i] < 32)
        {
          line[i] = 0;
          ret = i;
          break;
        }
    }

  if (ret == 0)
    {
      free(line);
      return 3;
    }

  int sum = line[ret-1] == line[0] && isdigit(line[ret-1]) ? line[ret-1] - '0' : 0;
  for (int i = 0; i < ret - 1; i++)
    {
      if (!isdigit(line[i]))
        {
          free(line);
          return 2;
        }
      if (line[i] == line[i+1])
        {
          sum += line[i] - '0';
        }
    }

  free(line);
  printf("%d\n", sum);
  return 0;
}
