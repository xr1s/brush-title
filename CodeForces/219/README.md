# Codeforces Round #135 (Div. 2)

## D. Choosing Capital for Treeland

给出一棵有向树。问如何选树根，才能通过调整最小的边指向，使得树根能抵达所有节点。

如果已经知道一个节点为根，其它边到这个点需要翻转几次路径方向，那么可以直接O(1)递推到相邻的点。

所以一次O(N)搜索，一次O(N)递推。