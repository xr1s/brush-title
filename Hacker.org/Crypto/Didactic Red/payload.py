#!/usr/bin/env python3

from PIL import Image

img = Image.open('redline.png')
width, height = img.size
for row in range(height):
    for col in range(width):
        r, g, b = img.getpixel((col, row))
        print(hex(r)[2:], end='')

