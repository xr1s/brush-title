from PIL import Image

prime = {p for p in range(2, 256) if all(p % q for q in range(2, p))}

op = Image.open('op.png')
width, height = op.size
qr = Image.new('L', (width, height))
for w in range(width):
    for h in range(height):
        r, g, b = op.getpixel((w, h))
        if r in prime:
            qr.putpixel((w, h), 255)
qr.show()

