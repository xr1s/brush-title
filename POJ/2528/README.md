# Mayor's posters

区间染色，每个颜色最多被染一次，问最后总共能看到多少种颜色。

因为区间太大，有1e7的位置，内存限制只有6MB，所以需要离散化。我直接sort+lower\_bound。

一个坑点是离散化后的操作，首先染[1,3]，然后另外两种颜色染[1,1],[3,3]会出现[2,2]被无视的情况，所以我们需要独立为2这个点保留一个离散的位置。其余也类似，对于离散后的区间，为中间一个点新建一个离散位置，再离散一次。

最后对于颜色，先把线段树所有的lazy标记下推到叶子，然后可以直接查询所有出现的颜色，可以用一个bool数组或者set来维护出现的颜色。

因为这个线段树不需要区间查询，所以直接建立lazy树即可。
