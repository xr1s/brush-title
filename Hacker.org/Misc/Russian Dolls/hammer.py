import gzip

data = open('doll.bin', 'rb').read()
while True:
    try:
        data = gzip.decompress(data)
    except OSError:
        print(data.decode())
        exit()
