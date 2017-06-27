from PIL import Image

img = Image.open('greenline.png')
width, height = img.size

for row in range(height):
    for col in range(width):
        r, g, b = img.getpixel((col, row))
        print(chr(g), end='')

