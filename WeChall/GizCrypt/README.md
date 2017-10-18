# GizCrypt

这是个简单的异或加密，明文和密钥的哪一位相对应是由算法决定的。算法比较简单，看代码即可。有两个计数器 k 和 x 初始 k=-1, x=1 ，对于明文的每一字节，k不停加x，如果k超过了密钥长度则重置为0，这时候x加一，如果x也超过了则也重置为1，然后明文该字节异或密钥第 k 字节（其实还有个无关紧要的异或'e'.ord）。这是一轮循环，一直到把明文全部异或一遍。

首先可以知道密钥长度确定之后，每个密钥只会加密对应的某一个明文，于是在长度确定的情况下我们可以知道某一位密钥加密了哪些密文，方便起见，我首先将它们分组。对于每一组，枚举密钥，如果解密的结果在字符集中则说明密钥有可能是这个字符，最后搜集所有可能的密钥判断有没有意义即可。这里的坑点在于字符集的枚举……我一开始的字符集不包含`:`字符，结果解不出来，纠结了好久。

而且我一开始本以为是要枚举密钥的长度的，结果在题目末尾直接告诉你了密钥的长度和字符集，这样瞬间简单无数。