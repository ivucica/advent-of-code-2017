import sys
from day4 import day4_lib

def main():
  idx = 1
  anagrams_banned = False
  while idx < len(sys.argv):
    if sys.argv[idx] == '--anagrams-banned':
      anagrams_banned = True
      sys.argv = sys.argv[:idx] + sys.argv[idx+1:]
    elif sys.argv[idx][:2] == '--':
      print 'usage: day4.py [file] [--anagrams-banned]'
      sys.exit(1)
    else:
      idx+=1

  if len(sys.argv) > 1:
    with open(sys.argv[1]) as f:
      print day4_lib.ValidPassphrases(f.readlines(), anagrams_banned)
  else:
    print day4_lib.ValidPassphrases(sys.stdin.readlines(), anagrams_banned)


if __name__ == '__main__':
  main()
