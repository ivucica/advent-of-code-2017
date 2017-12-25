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


const int GRIDW = 64, GRIDH = 64;
int64_t grid[GRIDW*GRIDH] = { 0 };

int64_t *
loc(x, y)
{
  return grid + ((GRIDH/2 + y) * GRIDW + GRIDW/2 + x);
}

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
  for(int i = 1; ; i++)
    {
      int sum = 0;
      if (x == 0 && y == 0)
        {
          sum = 1;
        }
      int int_x = GRIDW/2 + x, int_y = GRIDH/2 + y;

      sum += *loc(int_x-1, int_y);
      sum += *loc(int_x-1, int_y-1);
      sum += *loc(int_x, int_y-1);
      sum += *loc(int_x+1, int_y-1);
      sum += *loc(int_x+1, int_y);
      sum += *loc(int_x+1, int_y+1);
      sum += *loc(int_x, int_y+1);
      sum += *loc(int_x-1, int_y+1);

      *loc(int_x, int_y) = sum;

      if (sum > val)
        {
          printf("%d\n", sum);
          return 0;
        }

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

  return 0;
}
