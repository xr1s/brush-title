# Patience

一个class，反编译后发现是随机取值\*2+1执行2W次，取结果十进制最后9位判断是不是某个数，是则输出。

只要取最后9位，那就每次计算模1e9，甚至不会超int，然而题目用BigInteger自然巨慢，而且2W次迭代里每次都会toString，浪费时间。

改了一下用long保存，虽然还要等一会儿不过还是挺快的。
