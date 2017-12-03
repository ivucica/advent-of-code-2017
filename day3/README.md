# Day 3: Spiral Memory

## Disclaimer

Please solve for yourself. I'm posting my own solution for amusement purposes only.

## Solution description

I chose C once again.

This time input is not from stdin; rather it's the first argument on the command line.

Upon looking at the problem, I guessed there might be a mathematical solution.

But, I've also observed that my input is relatively small (on the order of 100000) so elected to do the stupid thing for the and simply iterate on the spiral until I encounter the input value.

There's a few hacks; for example, I've just beat the thing into submission by doing `x++`, `x--` and `y--` as needed instead of the usual movement based on direction. I am surprised that `x++` appears twice, but it works, so meh.

I've left `printf()`s in the code which I used to `printf`-debug the spiral simulation.

I suspect a simple improvement can be made by observing that `(n*2+1)^2` is on the diagonal line towards down right, while `(n*2)^2` is on the diagonal line towards up left as long as you first move one cell up.

A friend has also [sent me a spoiler](https://math.stackexchange.com/questions/163080/on-a-two-dimensional-grid-is-there-a-formula-i-can-use-to-spiral-coordinates-in) which I didn't click on until after writing the solution. He also mentioned that this is called an "ulam spiral".

## Problem text

[Solve for yourself](http://adventofcode.com/2017/day/3)

> You come across an experimental new kind of memory stored on an infinite two-dimensional grid.
>
> Each square on the grid is allocated in a spiral pattern starting at a location marked 1 and then counting up while spiraling outward. For example, the first few squares are allocated like this:
>
> ```
> 17  16  15  14  13
> 18   5   4   3  12
> 19   6   1   2  11
> 20   7   8   9  10
> 21  22  23---> ...
> ```
>
> While this is very space-efficient (no squares are skipped), requested data must be carried back to square `1` (the location of the only access port for this memory system) by programs that can only move up, down, left, or right. They always take the shortest path: the [Manhattan Distance](https://en.wikipedia.org/wiki/Taxicab_geometry) between the location of the data and square `1`.
>
> For example:
>
> - Data from square `1` is carried `0` steps, since it's at the access port.
> - Data from square `12` is carried 3 steps, such as: down, left, left.
> - Data from square `23` is carried only `2` steps: up twice.
> - Data from square `1024` must be carried `31` steps.
>
> *How many steps* are required to carry the data from the square identified in your puzzle input all the way to the access port?

