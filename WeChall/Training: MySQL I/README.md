# Training: MySQL I

古老的MySQL注入挑战。

我们仍然看到有SQL语句那一行，没有任何过滤，直接将username拼接到字符串中，而password被hash过，不存在注入点。

接着扫视源码，可知过关的条件是登录admin账户。

于是直接从username框进行最简单的注入吧。

用万能密码（帐号）注入username，得到的回显是Welcome back, AaronAAaronson!。这显然不是我们想要的帐号，所以加一句WHERE即可。
