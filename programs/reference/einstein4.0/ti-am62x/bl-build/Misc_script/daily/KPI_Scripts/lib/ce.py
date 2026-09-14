class ConfigFileParamError(KeyError): pass
class HTTPRequestFailError(Exception): pass
class InvalidStreamError(NameError): pass
class NoConfigFileError(FileNotFoundError): pass
class NoImpactColumnError(ValueError): pass

class InputStreamArgError(TypeError): pass
