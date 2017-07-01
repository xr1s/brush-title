with open('cipher') as f:
    cipher = f.read().split()

decrypt = {
    'A3': 'C', 'B4': 'o', '09': 'n', '6D': 'g', '97': 'r', '0F': 'a', 'C4': 't',
    '77': 'u', 'F4': 'l', 'A2': 'i', '17': 's', '74': '.', '32': ' ', 'E5': 'T',
    '71': 'h', '06': 'b', '8F': 'y', 'F1': 'V', '2B': 'e', '9A': 'w', 'DB': 'd',
    '75': 'p', 'A5': ',', '90': 'm', '26': 'c', '8E': 'k', '00': 'I', 'EF': 'Y',
    'D3': ':', '24': 'f',
}

for index, char in enumerate(cipher):
    if char in decrypt:
        cipher[index] = decrypt[char]

print(''.join(cipher))
