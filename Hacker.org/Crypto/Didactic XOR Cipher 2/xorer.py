cipher = 0x948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381
bytes  = 0x01010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101

for key in range(256):
    message = (cipher ^ bytes * key).to_bytes(46, 'big')
    try:
        message = message.decode()
    except UnicodeDecodeError:
        continue
    if message.isprintable():
        print(message)
