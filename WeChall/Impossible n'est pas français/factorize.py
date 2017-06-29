from sys import stderr
from getpass import getpass
from bs4 import BeautifulSoup
import requests


answer_url = 'http://www.wechall.net/en/challenge/impossible/index.php'
message_url = answer_url + '?request=new_number'

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
    # session start
    user.get(message_url).text
    # first try, get error message
    message = user.post(answer_url, {'solution': 1})
    message = BeautifulSoup(message.text, 'html.parser')
    message = message.select('.gwf_errors')[0].text[42:-3]
    # and post back
    response = user.post(answer_url, {'solution': message}).text
    response = BeautifulSoup(response, 'html.parser')
    answer_errors = response.select('.gwf_errors li')
    if answer_errors:
        exit(answer_errors[0].text)
    print(response.select('.gwf_messages li')[0].text)

