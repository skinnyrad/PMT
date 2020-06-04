# GDT demo
# generates stalled proess
# GDT should reboot it with output to stdout

from gdt import GDT
from os import getpid
from time import sleep
import sys

print("Program start")

gdt = GDT(3, pid=getpid())

print("stalling...")
while True:
    sleep(1)