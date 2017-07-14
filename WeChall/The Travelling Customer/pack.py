from getpass import getpass
from sys import stderr
import wechall
import requests

problem_url = 'http://www.wechall.net/challenge/training/programming/knapsaak/problem.php'
answer_url = 'http://www.wechall.net/challenge/training/programming/knapsaak/answer.php?answer={}'


def parse_question(question: str) -> ({str: int}, int, int, int, int):
    shelf, require = question.split('\n\n')
    commodities = {}
    for commodity in shelf.split():
        name, price = commodity.split('=')
        commodities[name] = int(price)
    require = require.split()
    size = int(require[0].split('=')[1])
    money = int(require[1].split('=')[1])
    stock = int(require[2].split('=')[1])
    level = int(require[3].split('=')[1])
    return commodities, size, money, stock, level


def multiple_pack(
        commodity: {str: int},
        size: int,
        money: int,
        stock: int) -> {str: int}:
    stock_base = [1]
    while stock_base[-1] << 2 < stock + 1:
        stock_base.append(stock_base[-1] << 1)
    if stock + 1 != stock_base[-1] << 1:
        stock_base.append(stock - (stock_base[-1] << 1) + 1)
    dp = {(0, 0): {}}
    for name, v in commodity.items():
        for k in stock_base:
            new = {}
            for n, m in dp:
                newn, newm = n + k, m + v * k
                if (newn, newm) in dp:
                    continue
                if newn == size and newm == money:
                    if name in dp[n, m]:
                        dp[(n, m)][name] += k
                    else:
                        dp[(n, m)][name] = k
                    return dp[(n, m)]
                if newn <= size and newm <= money:
                    new[(newn, newm)] = dp[(n, m)].copy()
                    if name in dp[(n, m)]:
                        new[(newn, newm)][name] += k
                    else:
                        new[(newn, newm)][name] = k
                else:
                    new[(newn, newm)] = {name: k}
            if (size, money) in new:
                return new[(size, money)]
            dp = {**dp, **new}


def parse_answer(answer: {str: int}) -> str:
    return ''.join(str(num) + name for name, num in answer.items())


if __name__ == '__main__':
    stderr.write('Username: ')
    username =  input()
    password = getpass()
    user = wechall.login(username, password)
    result = 'Correct. You are now on level 0.'
    while result.find('Correct') != -1 and result.find('solved') == -1:
        question = user.get(problem_url).text
        commodities, size, money, stock, level = parse_question(question)
        print('level', level, '\n' + question)
        answer = multiple_pack(commodities, size, money, stock)
        print(answer)
        answer = parse_answer(answer)
        # submit question
        result = user.get(answer_url.format(answer)).text
        print(result)
