# 传递

给出一个有向完全图的一个边拆分，问分成的两个子图是否是传递的。

bitset真的是黑魔法！n^3暴力过了！

标解应该是判环，只要出现一个环，整张图就不可能是传递的（因为没有自环，而如果被拆到不同的子图里，显然没法传递了，传递的环少了一部分），所以判环即可。