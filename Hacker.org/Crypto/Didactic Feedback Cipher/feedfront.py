c = 0x751a6f1d3d5c3241365321016c05620a7e5e34413246660461412e5a2e412c49254a24
c = c.to_bytes(35, 'big')
for k, v in enumerate(c):
    print(chr(v ^ c[k - 1]), end='')
