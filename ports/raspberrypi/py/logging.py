# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  microPython Firmware esp32spiram-idf3-20191220-v1.12
#  Filename : logging.py

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

_loggers = {}

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
        return level >= (self.level)

    def log(self, level, msg):
        if level >= (self.level):
            with open(self.logname, "a+") as fp:
                fp.write("{0}:{1}:{2}\n".format(self._level_str(level), self.name, msg))

    def write(self, msg):
        with open(self.logname, "a+") as fp:
            fp.write(msg)

    def overwrite(self, msg):
        with open(self.logname, "w+") as fp:
            fp.write(msg)

    def write_line(self, msg):
        with open(self.logname, "a+") as fp:
            fp.write("{0}\n".format(msg))

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
        #sys.print_exception(e, _stream)
        print("{0}: {1}".format(e,msg))

    def exception(self, msg):
        #self.exc(sys.exc_info()[1], msg)
        print(msg)


def getLogger(name, filename):
    if name in _loggers:
        return _loggers[name]
    l = Logger(name, filename)
    _loggers[name] = l
    return l


def openHomeDir(logger=None):
    from os import chdir, getlogin
    # must do this line by line, python gets mad otherwise
    chdir('/')
    chdir('home')
    chdir(getlogin())

# put python into runtime directory
def openRuntimeDir(logger=None):
    from os import chdir, access, mkdir, F_OK
    openHomeDir()
    if not access('runtime', F_OK): # if does not exist
        mkdir('runtime') # make it
    chdir('runtime')

# put python into runtime directory
def openPMTDir(logger=None):
    from os import chdir, access, F_OK, getlogin
    openHomeDir()
    if not access('PMT', F_OK): # if does not exist
        print("Error: PMT git repo not found in expected location!\n
        print("Expected in /home/{0}/PMT  Exiting...".format(getlogin()))
        if logger is not None:
            logger.error("PMT git repo not found in expected location!\nExiting...")
        exit()
    chdir('PMT')
    