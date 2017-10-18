from PIL import Image

img = Image.open('listen.png')
width, height = img.size
music = open('listen.mp3', 'wb')

for row in range(height):
    for col in range(width):
        r, g, b, a = img.getpixel((col, row))
        music.write(bytes([r, g, b]))
music.close()
