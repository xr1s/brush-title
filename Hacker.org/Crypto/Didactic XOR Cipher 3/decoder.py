cipher = 0x31cf55aa0c91fb6fcb33f34793fe00c72ebc4c88fd57dc6ba71e71b759d83588

cipher = cipher.to_bytes(32, 'big')

for b in range(256):
    if b ^ cipher[0] < 0x20 or b ^ cipher[0] >= 0x80:
        continue
    for x in range(256):
        msg = ''
        t = b
        for c in cipher:
            if 0x20 <= c ^ t < 0x80:
                msg += chr(c ^ t)
            else:
                break
            t = (t + x) % 256
        else:
            print(msg)
