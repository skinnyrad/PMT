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
#  Filename : machine.py

# This is an abstraction layer used in porting
# from micropython the python. As python does not 
# have a machine module



try:
    from os import popen, fork
    from subprocess import run
    import sys

except (ModuleNotFoundError, ImportError) as err:
    print("Error: Import failed in machine.py")
    print(err)
    exit()


def reset():
    popen("sudo reboot")

#TODO
def proc_restart(kill_pid, script=None):
    
    # fork off to new process
    fork_pid = fork()

    # If child process
    if fork_pid == 0:
        # popen this same process the way you do on bootup
        if script is not None:
            print("sudo python3 {}".format(script))
            run(["sudo", "python3", "{}".format(script)], stdin=sys.stdin, stdout=sys.stdout )
        elif len(sys.argv) > 0:
            print("sudo python3 {}".format( sys.argv[0] ))
            run( ["sudo", "python3", "{}".format(sys.argv[0])], stdin=sys.stdin, stdout=sys.stdout )
        else:
            print("No script provided, not restarted")
            exit()
    
    # Otherwise parent process

    # kill the stalled process
    popen("kill -s 9 {}".format(kill_pid))

    print("Parent: Exiting GDT process.")
    exit()
