import requests
from urllib.parse import quote as urlencode
from bs4 import BeautifulSoup
from sys import stderr
from getpass import getpass
import re

def login(username, password):
    session = requests.Session()
    login_url = 'http://www.wechall.net/login'
    session.get(login_url)  # set cookie
    form = {
        'username': username,
        'password': password,
        'login': 'Login',
    }
    response = session.post(login_url, form).text
    response = BeautifulSoup(response, 'html.parser')
    login_error = response.select('.gwf_errors li')
    if login_error:
        exit(login_error[0].text)
    return session

question = 'http://www.wechall.net/challenge/anto/FlowOverAstronomy/index.php'

if __name__ == '__main__':
    stderr.write('Your username: ')
    username = input()
    password = getpass('Your password: ')
    user = login(username, password)
    print('Logged in')
    html = user.get(question).text

    cs = re.findall('<div class="box_c">Charset: (.*?)<br/>', html)[0]
    print('Charset:', cs)

    ib = int(re.findall(r'<br/>Input Base: (\d+)<br/>', html)[0])
    print('Input Base:', ib)

    sb = int(re.findall(r'<br/>Solution Base: (\d+)<br/>', html)[0])
    print('Solution Base:', sb)

    e = re.findall(r'<div class="box_c">' + r'(.*)<br/>' * 5, html)[0]
    print('Equation:', e)

    e = re.split(' [+*] ', ''.join(e))
    print()
    print(e)

    for k, v in enumerate(e):
        n = 0
        for c in v:
            n = n * ib + cs[:ib].find(c)
        e[k] = n
    print()
    print(e)

    r = 1
    for i in range(len(e) - 1):
        r *= e[i]
    r += e[-1]
    print()
    print(r)

    rb = ''
    while r:
        rb += cs[r % sb]
        r //= sb
    rb = ''.join(reversed(rb))
    print()
    print(rb)

    print()
    html = user.get(question + '?action=Submit&answer=' + urlencode(rb)).text
    html = BeautifulSoup(html, 'html.parser')
    if html.select('.gwf_errors'):
        exit(html.select('.gwf_errors li')[0].text)
    print(html.select('.gwf_messages li')[0].text)

