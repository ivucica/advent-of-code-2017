import sys
from day4 import day4_lib

def main():
  if len(sys.argv) > 1:
    with open(sys.argv[1]) as f:
      print day4_lib.ValidPassphrases(f.readlines())
  else:
    print day4_lib.ValidPassphrases(sys.stdin.readlines())


if __name__ == '__main__':
  main()
