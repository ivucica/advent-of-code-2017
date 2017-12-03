#include <stdio.h>
#include <stdlib.h>

typedef enum _dir_t
{
  RIGHT = 0,
  UP = 1,
  LEFT = 2,
  DOWN = 3,
} dir_t;

typedef struct _velocity_t
{
  int x, y;
} velocity_t;

const velocity_t directions[] = {
  {
    .x = 1,
    .y = 0,
  },
  {
    .x = 0,
    .y = 1,
  },
  {
    .x = -1,
    .y = 0,
  },
  {
    .x = 0,
    .y = -1,
  }
};

int
main(argc, argv)
char ** argv;
{
  if (argc < 2)
    {
      fprintf(stderr, "usage: %s number\n", argv[0]);
      return 1;
    }

  int val = atoi(argv[1]);

  int x = 0, y = 0;
  int r = 0;
  dir_t dir = RIGHT;
  for(int i = 1; i <= val; i++)
    {
      dir_t newdir = dir;
      if (y == -r && dir == DOWN)
        {
          // printf("%d at %d %d, r = %d, turning right\n", i, x, y, r);
          newdir = RIGHT;
          if (i != val)
            x++;
        }
      else if (x == r && dir == RIGHT)
        {
          // printf("%d at %d %d, r = %d, turning up\n", i, x, y, r);
          newdir = UP;
          r++;
          if (i != val)
            x++;
        }
      else if (y == r && dir == UP)
        {
          // printf("%d at %d %d, r = %d, turning left\n", i, x, y, r);
          newdir = LEFT;
          if (i != val)
            x--;
        }
      else if (x == -r && dir == LEFT)
        {
          // printf("%d at %d %d, r = %d, turning down\n", i, x, y, r);
          newdir = DOWN;
          if (i != val)
            y--;
             
        }
      else
        {
          // printf("%d at %d %d, r = %d\n", i, x, y, r);
          if (i != val)
            {
              x += directions[dir].x;
              y += directions[dir].y;
            }
        }
      dir = newdir;
    }

  printf("%d\n", abs(x) + abs(y));

  return 0;
}
