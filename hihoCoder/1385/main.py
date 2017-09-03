import re

while True:
    occurrence = { }
    try: string = raw_input()
    except EOFError: exit()
    while string != '####':
        parts = re.split('[,.]', string)
        for part in parts:
            words = part.split()
            for phrase in zip(words, words[1:]):
                if phrase in occurrence:
                    occurrence[phrase] += 1
                else: occurrence[phrase] = 1
        string = raw_input()
    result = (('', ''), 0)
    for phrase, occur in occurrence.items():
        if occur > result[1]: result = (phrase, occur)
        elif occur == result[1] and phrase < result[0]:
            result = (phrase, occur)
    print ' '.join(result[0]) + ':' + str(result[1])
