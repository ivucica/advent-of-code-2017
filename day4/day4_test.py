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


class ValidPassphrasesTest(unittest.TestCase):

  def testAllInputs(self):
    self.assertEquals(day4_lib.ValidPassphrases([
        "aa bb cc dd ee\n",
        "aa bb cc dd aa\n",
        "aa bb cc dd aaa\n",]), 2)


if __name__ == '__main__':
  unittest.main()

