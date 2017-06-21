# Training: MySQL II

就加了一个判断，要求输入的password和服务器上查询出来的password相等。

这时候就必须用UNION SELECT来同时选中'admin'和自定义password了，不过在此之前，我们需要用ORDER BY来确认列数，本题验证出来是三列，第二列是username，第三列是password。然后就用UNION SELECT即可。

第一题也是可以这么做的，不过算是杀鸡用牛刀了。
