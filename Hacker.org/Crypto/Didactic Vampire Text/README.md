# Didactic Vampire Text

同样的，首先找这段文字在哪里出现过。是一部小说《德拉库拉》。

还是用`wdiff`，和原文比较，发现有很多处不同，而每处不同都是大小写的区别。一开始以为是二进制、培根密码什么的，直接wdiff可以看出来一点端倪，就是修改后的文章中所有大写的字母看得出来有YOUR ANSWER SUNSHINE的样子。

但是不对呀，显然有些字母没有被筛出来，还筛出了一些奇怪的东西。

继续进文件检查。会发现大写字母特别少……结果全部筛选出来就有答案。之前用wdiff只筛选出了小写变成大写的那一部分，原文也有一些大写的是没变的。

