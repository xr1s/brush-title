cipher = 0x310a7718781f734c31425e775a314f3b40132c5122720599b2dfb790fd8ff894add2a4bdc5d1a6e987a0ed8eee94adcfbb94ee88f382127819623a404d3f
cipher = cipher.to_bytes(62, 'big')

for x in range(256):
    message = ''
    for i in range(1, len(cipher)):
        if 0x20 <= cipher[i - 1] + x & 0xff ^ cipher[i] < 0x7f:
            message += chr(cipher[i - 1] + x & 0xff ^ cipher[i])
        else:
            break
    else:
        print(message)

