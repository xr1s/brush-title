from PIL import Image
from os import system

with Image.open('Doll2.png') as img:
    with open('Doll2.exe', 'wb') as lzma:
        lzma.write(bytes(img.getdata()))

system('''
7z e -so Doll2.exe \
    | perl \
    | python2 \
    > Doll2.c \
    && gcc Doll2.c -o Doll2 \
    && ./Doll2 \
''')
