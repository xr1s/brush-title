# Didactic Feedback Cipher Long 2

这题最坑的就在于那句莫名其妙的`c = (txt[i] -> txt[i + 3]) ^ k`，真的是题意不清。

`(txt[i] -> txt[i + 3])`的意思是`txt[i:i+3]`以小端序解码，也就是前面的低位后面的高位。

Hacker.org的Feedback加密系列后面的k和前面的k关系不大，可以直接由前面的密文推导出来，这里在已经给出了密文的情况下，我们可以选择性不解码前四个字符，枚举x的每一位，因为每一位的加密是独立的，所以只要其中一位不合法（这里我认为只有可见字符合法）就说明接下去的不可能合法，直接`continue`，这是一个很好用的剪枝。再利用前四个字符推导出第二个k，接下去直接递推即可解码。

x的范围是unsigned，取余的部分利用了自然溢出。

前四个字符的关系不是很大，不过我猜是"i ha"。