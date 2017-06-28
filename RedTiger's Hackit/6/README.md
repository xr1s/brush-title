# level 6

所以题目里的这个什么with status 1是什么意思？

首先正常套路，在GET参数里试图注入，xjb打了一串，也试了一下`XMLUPDATE`，直接被禁了……

`ORDER BY`了一下，有5列，然后`UNION SELECT`了一下`1,2,3,4,5`，没有任何回显，提示没有此用户，我：？

想到可能是user id太大了，重新`UNION SELECT 1,1,1,1,1`，提示没有此用户，我：？？

猜测后面的逻辑可能是先`SELECT`了user id得到username等信息，再通过username在另一个表里`SELECT`出username和email。如果是这样的话，我们就需要在`UNION SELECT`的各项里找到那个被用于查询的那一列，利用它向另一个列里注入。

然后5个都试`'deddlef'`过去，报错×5，我：？？？

然后注意到，只要语句里出现引号就会报错，似乎有被`addslashes`，既然如此，又不需要闭合引号的情况下，直接`hexlify(b'deddlef')`，五个都试过去，在第二列成功选中了deddlef。

猜想正确了，剩下的就是直接构造payload，在第二列里注入。

首先也是`ORDER BY`，得到列数4，显位为2和4。

接着就`SELECT 1, username, 3, password, 5 FROM level6_users WHERE username='admin'`出来了。

