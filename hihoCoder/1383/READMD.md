# The Book List

要求把目录以要求的形式列出来。每一级里，目录先列，然后是书，目录和书各自按照字典序列出，每一级缩进四个空格。

还是个递归思想吧。最最重要的是**书可以和目录重名！**一开始用C++写各种WA，然后用Python重写了一遍还是RE。仔细想了一下RE点只有对None取[]了，可能是重名的问题，然后给书和目录加了个前缀，输出舍弃就好了。