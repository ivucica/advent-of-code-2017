#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "diff_for_line.h"

#define TRY(input, expect) \
  input_modifiable = malloc(strlen(input)); \
  memcpy(input_modifiable, input, strlen(input)+1); \
  out = diff_for_line(input_modifiable, strlen(input)); \
  if (out != (expect)) \
    { \
      status = 1; \
      fprintf(stderr, "for input %s, expected = %d, got = %d\n", input, (expect), out); \
    } \
  free(input_modifiable);

int
main()
{
  int status = 0;
  int out = 0;
  char * input_modifiable = NULL;
 
  TRY("5 1 9 5\n", 8)
  TRY("7\t5\t3\n", 4)
  TRY("2\t4 6\t8\n", 6)

  return status;
}
