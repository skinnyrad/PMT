# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  Raspbian Lite version February 2020
#  Python 3.7
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

    def __init__(self, name, location):
        self.name = name
        self.location = location

    def _level_str(self, level):
        l = _level_dict.get(level)
        if l is not None:
            return l
        return "LVL%s" % level

    def setLevel(self, level):
        self.level = level

    def setLocation(self, location):
        self.location = location

    def isEnabledFor(self, level):
        return level >= (self.level)

    def log(self, level, msg):
        if level >= (self.level):
            with open( self.location, "a+") as fp:
                fp.write("{0}:{1}:{2}\n".format(self._level_str(level), self.name, msg))

    def write(self, msg):
        with open(self.location, "a+") as fp:
            fp.write(msg)

    def overwrite(self, msg):
        with open(self.location, "w+") as fp:
            fp.write(msg)

    def write_line(self, msg):
        with open(self.location, "a+") as fp:
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
    openPMTDir()
    if not access('runtime', F_OK): # if does not exist
        mkdir('runtime') # make it
    chdir('runtime')

# put python into /boot/PMT/ directory
def openPMTDir(logger=None):
    from os import chdir, access, F_OK, getlogin
    PMT_dir = '/home/{}/PMT'.format(getlogin())
    
    if not access(PMT_dir, F_OK): # if does not exist
        print("Error: PMT git repo not found in expected location!\n")
        print("Expected in /boot/PMT  Exiting...")
        if logger is not None:
            logger.error("PMT git repo not found in expected location /boot/PMT\nExiting...")
        exit()
    chdir('PMT')
    