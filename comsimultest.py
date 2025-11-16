#comsimultest.py
import unittest
from compile_simulater_v2.so import interpreterhl
from compile_simulater_v2.so import compilerhlan
from compile_simulater_v2.so import Assemblylan


class comsimultest(unittest.TestCase):
  def test_comp(self):
    comp=compilerhlan("1234", 0)
    self.assertEqual(comp.get(), 1234)
  def test_interp(self):
    interp=interpreterhl("2345", 0)
    self.assertEqual(interp.get(), 2345)
  def test_assembly(self):
      a = Assemblylan("456", 0)
      self.assertEqual(a.get(), "456")
      self.assertEqual(a.pre_get(), 0)
if __name__ == '__main__':
    unittest.main()
