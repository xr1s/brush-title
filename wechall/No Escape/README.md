# No Escape

The small gizmore software company is expanding, and got contracted to create the new online votings for presidental election in 2012.

The current script is in alpha phase, and we`d like to know if it`s safe.

To prove me wrong you have to set the votecount for at least one of the candidates to 111. There is a reset at 100.

## 翻译

一个投票系统，在每次某个人的票数达到100都会直接清空。你需要给任意一人投到111票。

## 解题报告

直接去代码里找SQL语句，在第72行。而在71行有`mysql_real_escape_string`了输入。

然而我们的注入点并没有被`'`包围，而输入里有反引号的不会被添加上反斜杠。于是可以轻易闭合反引号。可以用注释符，所以很容易就可以修改值。

从投票界面可以拿到三个分别给不同人投票的url，我们猜测是这个函数里的$who注入点，所以构造payload绕过。

JHSN提出来的一道思考题：如何在不使用注释符的情况下做到投到111票。可以考虑去试一试。
