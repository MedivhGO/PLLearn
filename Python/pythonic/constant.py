
"""
constant variable 
"""
class _const(object):
	class ConstError(TypeError): pass
	class ConstCaseError(ConstError): pass

	def __setattr__(self, name, value):
		if self.__dict__.has_key(name):
			raise self.ConstError, "Can't change const.%s " % name
		if not name.isupper():
			raise self.ConstCaseError,\
							'const name "%s" is not all uppercase '%name
		self.__dict__[name] = value

import sys
sys.modules[__name__] = _const()
import const
const.MY_CONSTANT = 1
const.MY_SECOND_CONSTANT = 2