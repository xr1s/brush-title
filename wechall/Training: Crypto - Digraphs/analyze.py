#!/usr/bin/env python3

from operator import itemgetter

cipher = 'gzrjiahifhojjhohelojjheqrjiamrfm hkrjoh lrvqcvfhbkoejhvqlr jhokeqmr zmvqmrmrojhivq mrohcvcvvqmrmrnxohelelbkfm erojmr iarjjh jhrjrj lreqnxnxeqcvoheljh vqeqjhokvqfhjy zdojmr eqjhan ervqeleljy hirjrjlr mhrjaefm cniajhvqfh jhokeqmr rkvqbkzdrjfhlr ojmr mrrjelohjheqrjiafe fhaelrlreqrjaeianxaeaeoefm'.split()
occur = {}
decode = {}

for word in cipher:
    for i in range(0, len(word), 2):
        char = word[i] + word[i + 1]
        if char not in occur:
            occur[char] = 0
            decode[char] = '#' + char + '#'
        occur[char] += 1

occur = sorted(occur.items(), key=itemgetter(1), reverse=True)
print(dict(occur))

# 完全靠感觉decode
decode['gz'] = 'C'
decode['rj'] = 'o'
decode['ia'] = 'n'
decode['hi'] = 'g'
decode['fh'] = 'r'
decode['oj'] = 'a'
decode['jh'] = 't'
decode['oh'] = 'u'
decode['el'] = 'l'
decode['eq'] = 'i'
decode['mr'] = 's'
decode['fm'] = '.'
decode['hk'] = 'Y'
decode['ok'] = 'h'
decode['zm'] = 'm'
decode['vq'] = 'e'
decode['cv'] = 'c'
decode['nx'] = 'f'
decode['bk'] = 'y'
decode['lr'] = 'd'
decode['oe'] = 'p'
decode['rk'] = 'k'
decode['zd'] = 'w'
decode['cn'] = 'E'
decode['fe'] = ':'
decode['mh'] = 'j'
decode['ae'] = 'b'
decode['jy'] = ','
decode['an'] = '?'
decode['er'] = 'W'


for word in cipher:
    for i in range(0, len(word), 2):
        char = word[i] + word[i + 1]
        print(decode[char], end='')
    print(end=' ')

