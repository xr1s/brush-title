# Didactic Scrambled Egg Cipher Pre-Warmup

这题没有观察出什么规律，但是可以发现这个操作是可逆的：首先异或了一个数，然后循环移位，重复三次。

于是根据此逆向出了解密算法，但是没有密钥，这就需要枚举了。密钥有4字节，也就是超过42亿的可能性，复杂度还要乘上字符串长度，大概是O(2^key\*len)，嫌脚本语言太慢，写了个C，挂服务器上跑了。不知道有没有什么优化算法。

晚上打完Codeforces回来发现跑出来一堆……在一坨字符串里找到了一句读得通顺的，就是答案了，打印出key是334becaa，让你去搜一句话是谁说的，在维基语录找到了这句话，提交他的姓即可。

看到了下一题，感觉应该还有什么规律没有发现。