# Road Construction

给出一张图，生成一棵树，使得在路径最短的情况下费用最小。

双关键字的最短路，记录一下根到每个点最短距离以及最小费用的前驱边，最后输出的时候只要把每个点最小的前驱相加就可以了，因为对于一棵树来说，除了根节点都会有一个前驱的边，而最短路的更新策略保证不可能更新一个环出来（除非有负权回路），所以这些边加起来是一棵树。
