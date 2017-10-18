#!/usr/bin/env python2

from pwn import *

print asm('''
        xchg eax,esp
        ret
        mov ecx,[eax]
        mov [edx],ecx
        pop ebx
        ret
''').encode('hex').upper()
