# Ambiguous Permutations

题意是给一串排列，判断它的“逆排列”是否和它本身一样。所谓的“逆排列”就是指对每个数给出它在排列中的下标。

所以其实就是看看它的逆映射是不是本身，也就是f(f(i))==i，一个O(n)判断即可。
