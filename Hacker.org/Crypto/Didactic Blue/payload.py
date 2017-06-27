from PIL import Image

img = Image.open('blue.png')
width, height = img.size

for row in range(height):
    for col in range(width):
        r, g, b = img.getpixel((col, height - row - 1))
        print(chr(b), end='')
    print()

