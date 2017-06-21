from sys import stderr
from getpass import getpass
from bs4 import BeautifulSoup
import requests

message_url = 'http://www.wechall.net/challenge/training/programming1/index.php?action=request'
answer_url = 'http://www.wechall.net/challenge/training/programming1/index.php?answer={message}'

def login(username=None, password=None):
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

if __name__ == '__main__':
    stderr.write('Your username: ')
    username = input()
    password = getpass('Your password: ')
    user = login(username, password)
    message = user.get(message_url).text
    print('first message:', message)
    response = user.get(answer_url.format(message=message)).text
    response = BeautifulSoup(response, 'html.parser')
    answer_errors = response.select('.gwf_errors li')
    if answer_errors:
        exit(answer_errors[0].text)
    print(response.select('.gwf_messages li')[0].text)

