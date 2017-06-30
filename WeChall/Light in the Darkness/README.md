# Light in the Darkness

看到18行的卖萌没？回显错误，是报错注入。

我使用了我日常的`EXTRACTVALUE`，没有回显，一脸懵逼。搞了半天发现是`UNION SELECT`后不是`password`的作用域，而且`blight`这串字符多半是被过滤了。用`AND`和`password`又提示

> Only constant XPATH queries are supported

XPATH报错大概是无解了，于是我换了个报错注入的方法，就是著名的Duplicate entry方法，也就是`floor(rand(0)*2)`。

