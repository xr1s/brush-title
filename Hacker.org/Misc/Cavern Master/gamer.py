#!/usr/bin/env python3

from hacker import login, LoginError

from bs4 import BeautifulSoup
import re
import random
import queue
from sys import stderr
from getpass import getpass

dirname = {
    'w': 'west',
    'e': 'east',
    'n': 'north',
    's': 'south',
    'd': 'downstair',
}

class Weapon(object):
    def __init__(self, desc):
        desc = desc.split()
        if len(desc) == 3:
            _, level, name = desc
            point = 0
        elif len(desc) == 4:
            _, level, name, point = desc
        self.name = name
        self.level = int(level)
        self.point = int(point)

    def __str__(self):
        level = str(self.level)
        point = str(self.point)
        return 'Level ' + level + ' ' + self.name + ' +' + point

    def __repr__(self):
        level = str(self.level)
        point = str(self.point)
        return 'Level ' + level + ' ' + self.name + ' +' + point

    def __eq__(self, new):
        return self.level == new.level and self.point == new.point

    def __ne__(self, new):
        return self.level != new.level or self.point != new.point

    def __lt__(self, new):
        if self.level < new.level:
            return True
        if self.level == new.level and self.point < new.point:
            return True
        return False

    def __le__(self, new):
        return self < new or self == new

    def __gt__(self, new):
        if self.level > new.level:
            return True
        if self.level == new.level and self.point > new.point:
            return True
        return False

    def __ge__(self, new):
        return self > new or self == new

class Potion(object):
    def __init__(self, desc):
        desc = desc.split()
        point = 0
        if len(desc) == 2:
            name, _ = desc
        elif len(desc) == 3:
            name, _, point = desc
        self.name = name
        self.point = int(point)

    def __str__(self):
        return self.name + ' potion +' + str(self.point)

    def __repr__(self):
        return self.name + ' potion +' + str(self.point)


class Block(object):
    def __init__(self, move, pre=None, predir=''):
        self.vis = False
        self.dir = move
        self.link = {
            'w': None,
            'e': None,
            'n': None,
            's': None,
            'd': None,
        }
        if predir and predir in 'wens':
            suc = 'wens'.find(predir)
            self.link[suc] = pre
            pre.link[predir] = self

    def __str__(self):
        return self.dir


class Gamer(object):
    url = 'http://www.hacker.org/challenge/misc/d/cavern.php'

    def __init__(self, user):
        self.user = user
        self.depth = 0
        self.level = 0
        self.hp = 0
        self.xp = 0
        self.weapon = None
        self.inventory = []

    def userinfo(self, desc):
        if desc.find('?reset=1') != -1:
            desc = self.user.get(Gamer.url + '?reset=1')
        desc = BeautifulSoup(desc, 'html.parser')
        self.depth = int(desc.h2.text.split()[-1])
        info = desc.table('tr')[2]('td')
        self.level = int(info[0].text)
        self.hp = int(info[1].text)
        self.xp = int(info[2].text)
        self.weapon = Weapon(info[3].text)
        self.inventory = self.get_inventory(desc.table('tr')[3].text)
        return desc

    def login(self):
        desc = self.user.get(self.url).text
        if desc.find('not logged in') != -1:
            raise LoginError('not logged in')
        html = self.userinfo(desc)
        self.location = Block(self.get_state(html('a')))
        return desc

    def get_inventory(self, desc):
        inventory = []
        for item in desc.split('\n')[2:-1]:
            inventory.append(Potion(item))
        return inventory

    def get_state(self, a):
        move = ''
        for lnk in a:
            key, val = lnk['href'].split('?')[1].split('=')
            if key == 'm':
                move += val
            elif key == 'attack':
                desc = self.fight()
                desc = BeautifulSoup(desc, 'html.parser')
                return self.get_state(desc('a'))
            elif key == 'tres':
                if len(lnk.text.split()) == 4:
                    new_weapon = Weapon(lnk.text)
                    if new_weapon > self.weapon:
                        self.user.get(Gamer.url + '?tres=1')
                        self.weapon = new_weapon
                        print('You picked up a new weapon', self.weapon)
            elif key == 'potion':
                pass
            else:  # DEBUG
                print(key, val)
                input('unknow link')
        return move

    def fight(self):
        desc = self.user.get(Gamer.url).text
        try:
            # monsters' infomation, includes name of boss
            print(re.search(r'<p>\s(.*)<br>', desc).group(1))
        except AttributeError:
            # will only occur when multiply threads logged in
            pass
        print('=' * 40)
        if desc.find('death') != -1:
            print('You died')
            return user.login()
        while desc.find('Attack!') != -1:
            desc = self.user.get(Gamer.url + '?attack=1').text
            msg = re.findall(r'(?:You|The monster).*?!', desc)
            for announce in msg:
                print(announce)
            blood = int(re.findall(r'<td>(\d+)</td>', desc)[1])
            print('Your blood', blood)
        self.userinfo(desc)
        print('Level:', self.level)
        print('Xp:', self.xp)
        print('=' * 40)
        return desc

    def random_move(self):
        direction = 'd'
        while direction == 'd':
            direction = random.choice(str(self.location))
        print('You move', dirname[direction])
        desc = self.user.get(Gamer.url + '?m=' + direction).text
        desc = BeautifulSoup(desc, 'html.parser')
        block = Block(self.get_state(desc('a')), self.location, direction)
        self.location = block

    def down_stair(self):
        desc = self.user.get(Gamer.url).text
        desc = BeautifulSoup(desc, 'html.parser')
        block = Block(self.get_state(desc('a')))
        self.location = block
        direction = ''
        while direction != 'd':
            if 'd' not in str(self.location):
                direction = random.choice(str(self.location))
            else:
                direction = 'd'
            print('You move', dirname[direction])
            desc = self.user.get(Gamer.url + '?m=' + direction).text
            desc = BeautifulSoup(desc, 'html.parser')
            state = self.get_state(desc('a'))
            block = Block(state, self.location, direction)
            self.location = block


if __name__ == '__main__':
    stderr.write('Username: ')
    username = input()
    password = getpass()
    user = login(username, password)
    gamer = Gamer(user)
    gamer.login()
    while True:
        while gamer.level <= gamer.depth + 5:
            gamer.random_move()
        else:
            print('Level:', gamer.level)
            print('Depth:', gamer.depth)
            print('Weapon:', gamer.weapon)
            print('Potion:', gamer.inventory)
            gamer.down_stair()

