#!/usr/bin/env python3

from hacker import login
from sys import argv, stderr
from getpass import getpass
from PIL import Image


def getaccount():
    return 'xris', 'uestc-22-2-4-4-xris'
    stderr.write('Username: ')
    username = input()
    password = getpass()
    return username, password


def load_image(session):
    url = 'http://www.hacker.org/challenge/misc/stars.php'
    session.get('http://www.hacker.org/challenge/chal.php?id=79')
    with open('stars.png', 'wb') as stars:
        stars.write(session.get(url).content)
    return Image.open('stars.png')


def parse_image(image):
    white = (230, 230, 230)
    black = (223, 145, 44)
    width, height = image.size
    width = width // 16
    height = height // 16
    message = []
    for row in range(height):
        byte = 0
        for col in range(width):
            x = 16 * row + 8
            y = 16 * col + 8
            color = image.getpixel((y, x))
            if color == white:
                byte = byte << 1 | 1
            if color == black:
                byte = byte << 1 | 0
        message.append(byte)
    return bytes(message)


def main():
    url = 'http://www.hacker.org/challenge/chal.php?answer=%s&id=79&go=Submit'
    s = login(*getaccount())
    img = load_image(s)
    msg = parse_image(img).decode()
    result = s.get(url % msg).text
    st = result.find('<font color=')
    ed = result.find('</b></font>')
    print(result[st + 22:ed])


if __name__ == '__main__':
    main()
