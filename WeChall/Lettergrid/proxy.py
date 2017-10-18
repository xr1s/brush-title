#!/usr/bin/env python3

from wechall import login
from subprocess import Popen, PIPE
from sys import stderr
from getpass import getpass
from bs4 import BeautifulSoup
import re

base = 'http://www.wechall.net/challenge/lettergrid/'

def main():
    proc = Popen(['./trie', 'dictionary'], stdin=PIPE, stdout=PIPE)
    stderr.write('Username: ')
    username = input()
    password = getpass()
    s = login(username, password)
    s.get(base)
    grid = s.get(base + 'generate.php').content
    grid = re.findall(br'<pre>(.*)</pre>', grid, re.S)[0]
    out, err = proc.communicate(grid.strip())
    submit = '?solution=' + out.strip().decode() + '&cmd=Submit+Answer'
    result = BeautifulSoup(s.get(base + submit).text, 'html.parser')
    if result.select('.gwf_errors li'):
        exit(result.select('.gwf_errors li'))
    print(result.select('.gwf_messages li'))


if __name__ == '__main__':
    main()
