import unittest

from day4 import day4_lib

class ValidPassphraseTest(unittest.TestCase):
  
  def testEmpty_valid(self):
    self.assertFalse(day4_lib.ValidPassphrase(""))
  
  def testSingleWord_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("abc"))
 
  def testFirstInput_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("aa bb cc dd ee"))
 
  def testSecondInput_invalid(self):
    self.assertFalse(day4_lib.ValidPassphrase("aa bb cc dd aa"))
 
  def testThirdInput_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("aa bb cc dd aaa"))

  def testFirstAnagramBan_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("abcde fghij", True))

  def testSecondAnagramBan_invalid(self):
    self.assertFalse(day4_lib.ValidPassphrase("abcde xyz ecdab", True))

  def testThirdAnagramBan_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("a ab abc abd abf abj", True))

  def testFourthAnagramBan_valid(self):
    self.assertTrue(day4_lib.ValidPassphrase("iiii oiii ooii oooi oooo", True))

  def testFifthAnagramBan_invalid(self):
    self.assertFalse(day4_lib.ValidPassphrase("oiii ioii iioi iiio", True))


class ValidPassphrasesTest(unittest.TestCase):

  def testAllInputs(self):
    self.assertEquals(day4_lib.ValidPassphrases([
        "aa bb cc dd ee\n",
        "aa bb cc dd aa\n",
        "aa bb cc dd aaa\n",]), 2)

  def testAllInputsWithAnagramBan(self):
    self.assertEquals(day4_lib.ValidPassphrases([
        "abcde fghij\n",
        "abcde xyz ecdab\n",
        "a ab abc abd abf abj\n",
        "iiii oiii ooii oooi oooo\n",
        "oiii ioii iioi iiio\n",], True), 3)


if __name__ == '__main__':
  unittest.main()

