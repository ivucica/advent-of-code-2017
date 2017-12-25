
def ValidPassphrase(pp, anagrams_banned=False):
  """ValidPassphrase accepts a str, and returns a bool whether a passphrase is valid.

  A passphrase is a str containing words separated by exactly one space.
  It is valid if no word repeats within the passed passphrase.

  Args:
    pp: str, passphrase
    anagrams_banned: bool, whether anagrams of a word are considered to be the
        same word
  """
  words = pp.rstrip().split(' ')
  if anagrams_banned:
    words = [''.join(sorted(word)) for word in words]
  word_set = set(words)
  return len(pp) and len(word_set) == len(words)


def ValidPassphrases(passphrase_list, anagrams_banned=False):
  """ValidPassphrases accepts an iterable of str, each of which is a passphrase.

  Any whitespace at the end, including newlines, will be stripped away first.

  Args:
    passphrase_list: iterable of str, all passphrases
    anagrams_banned: bool, whether anagrams of a word are considered to be the
        same word
  """
  cnt = 0
  for pp in passphrase_list:
    if ValidPassphrase(pp.rstrip(), anagrams_banned):
      cnt += 1
  return cnt

