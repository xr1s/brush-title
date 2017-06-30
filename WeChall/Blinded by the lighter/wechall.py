from bs4 import BeautifulSoup
from requests import Session

class LoginError(Exception):
    def __init__(self, message):
        super().__init__(message)

def login(username, password):
    session = Session()
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
        raise LoginError(login_error[0].text)
    return session

