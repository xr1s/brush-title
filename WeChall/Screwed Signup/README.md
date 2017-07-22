# Screwed Signup

所有的用户名都被escape，密码都加上了md5。

之后去查了一下`INSERT IGNORE INTO`，只是忽视插入的重复记录，也就是没法修改Admin账户的密码。

这题的重点在于`screwed_signupIsValidUsername`函数里，`preg_match`匹配的位数是`{3,64}`，也就是最多64位，而数据库中用户名字段的定义是```username` VARCHAR(24) NOT NULL,``，这里有一个截断的危险。

可以看到，登录的逻辑被分成了三部分，首先检查用户存在，再检查用户名密码是否匹配，再获取用户信息。

这里，利用截断，首先注册一个用户名里后缀空格的用户，为了防止注册的时候被`trim`掉空格，应当在末尾加入其它字符。

然后利用MySQL的一个[特性](https://dev.mysql.com/doc/refman/5.7/en/string-comparison-functions.html)，在`SELECT`的时候会无视记录中和`WHERE`限定的字段值的尾部空格，也就是``SELECT * FROM `chall_sql1` WHERE `username`='Admin '``的返回值``SELECT * FROM `chall_sql1` WHERE `username`='Admin'``一样，这样`SELECT`返回的第一条就是一开始插入的Admin，于是成功登录Admin。

