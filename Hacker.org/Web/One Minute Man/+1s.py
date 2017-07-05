#!/usr/bin/env python3

from urllib.request import urlopen
from datetime import datetime
from time import sleep

url = 'http://www.hacker.org/challenge/misc/minuteman.php'

while True:
    response = urlopen(url).read()
    if response != b'<html><body>\nback later':
        print(datetime.now().strftime('%H:%M'), response)
    sleep(50)

