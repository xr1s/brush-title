# 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest

## B. 3D City Model

在一个矩阵里搭积木，给出每一块积木拼成的立体图形的高度（还是看图好了，不知道怎么形容），求表面积。

就是从四个方向，每两行每两列之间的高度差就是露出来的面积，求和加上上表面和下表面就好。

## D. Fire in the Country

一张图，火从首都开始烧，两个人轮流控制机器人从首都开始逃跑，都是一次移动一格。当然，机器人永远不可能逃脱被烧毁的结局，重点是两个人都尽可能使机器人在对方控制的那一轮被火烧死。

这个不是一个SG博弈局面。因为机器人速度和火的速度相同，所以机器人不可能往深度更小或者相等的地方走，所以其实可以走的路径最终还是形成了一棵树的形状。

可以树形DP，首先显然两个人要尽可能使得对方那一轮机器人遇到死路，所以先手尽可能往和根的距离为偶数的叶子走，后手应该尽可能往和根的距离为奇数的叶子走，于是我们判一下当前节点的奇偶性质，偶节点是先手控制局面，先手只会往后手走不到先手必败局面的子节点走，而后手只会往先手必败局面走，递归的终点是叶子节点，如果是奇节点是先手必胜，反之先手必败。


## J. Buoys

x轴上有一些点，移动最少的距离，使得每一对相邻的点距离相等。

这题刘大爷给出了一个他也不会证明的暴力，总之就是固定任意两个，其它的直接算，取移动的最小的就可以了。

