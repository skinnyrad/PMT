import sys

CRITICAL = 50
ERROR    = 40
WARNING  = 30
INFO     = 20
DEBUG    = 10
NOTSET   = 0

_level_dict = {
    CRITICAL: "CRIT",
    ERROR: "ERROR",
    WARNING: "WARN",
    INFO: "INFO",
    DEBUG: "DEBUG",
}

_stream = sys.stderr

class Logger:

    level = NOTSET

    def __init__(self, name, logname):
        self.name = name
        self.logname = logname

    def _level_str(self, level):
        l = _level_dict.get(level)
        if l is not None:
            return l
        return "LVL%s" % level

    def setLevel(self, level):
        self.level = level

    def setLogname(self, logname):
        self.logname = logname

    def isEnabledFor(self, level):
        return level >= (self.level or _level)

    def log(self, level, msg):
        if level >= (self.level or _level):
            with open(self.logname, "a+") as fp:
                fp.write("%s:%s:%s\n" % (self._level_str(level), self.name, msg))

    def debug(self, msg):
        self.log(DEBUG, msg)

    def info(self, msg):
        self.log(INFO, msg)

    def warning(self, msg):
        self.log(WARNING, msg)

    def error(self, msg):
        self.log(ERROR, msg)

    def critical(self, msg):
        self.log(CRITICAL, msg)

    def exc(self, e, msg):
        self.log(ERROR, msg)
        sys.print_exception(e, _stream)

    def exception(self, msg):
        self.exc(sys.exc_info()[1], msg)

_loggers = {}

def getLogger(name, filename):
    if name in _loggers:
        return _loggers[name]
    l = Logger(name, filename)
    _loggers[name] = l
    return l
