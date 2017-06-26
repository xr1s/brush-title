#!/usr/bin/env python3

from PIL import Image

img = Image.open('didactrgb.png')
r, g, b = img.getpixel((0, 0))
print(r << 16 | g << 8 | b)

