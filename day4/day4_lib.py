
def ValidPassphrase(pp):
  """ValidPassphrase accepts a str, and returns a bool whether a passphrase is valid.

  A passphrase is a str containing words separated by exactly one space.
  It is valid if no word repeats within the passed passphrase.
  """
  words = pp.rstrip().split(' ')
  word_set = set(words)
  return len(pp) and len(word_set) == len(words)


def ValidPassphrases(passphrase_list):
  """ValidPassphrases accepts an iterable of str, each of which is a passphrase.

  Any whitespace at the end, including newlines, will be stripped away first.
  """
  cnt = 0
  for pp in passphrase_list:
    if ValidPassphrase(pp.rstrip()):
      cnt += 1
  return cnt

