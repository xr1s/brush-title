import requests

login_url = 'http://www.hacker.org/forum/login.php'
forum_url = 'http://www.hacker.org/forum/index.php'

class LoginError(BaseException):
    def __init__(self, message):
        super().__init__(self, message)

def login(username, password):
    session = requests.Session()
    form = {
        'username': username,
        'password': password,
        'login': 'Log in',
    }
    redirect = session.post(login_url, form).url
    if redirect.find(forum_url) == -1:
        raise LoginError('username or password error')
    return session

