# Farey Sequence

[题目来自室友的博客](http://blog.chrstm.com/2017/08/26/Farey_Sequence/)

求Farey序列，其定义为为所有大小介于0, 1之间且分母不大于n的最简分数。

递归法，结论非常简单，证明非常巧妙。对于两个真分数a/b\<c/d，可以证明a/b\<(a+c)/(b+d)\<c/d，再证明在bc-ad=1的时候，gcd(a+c,b+d)=1，构造

(a+c)b-(b+d)a=bc-ad=1,
(b+d)c-(a+c)d=bc-ad=1.

于是可以得到结论是gcd(a+c,b+d)=1。这样，我们从0/1和1/1开始，依次可以构造出整个序列。直到分母大于n为止。
