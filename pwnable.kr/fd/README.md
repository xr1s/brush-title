# fd

从`fd`中`read`字符，和`"LETWIN"`相等则输出flag。

我们知道file descriptor 0是stdin，所以输入0 + 0x1234 = 4660即可。
