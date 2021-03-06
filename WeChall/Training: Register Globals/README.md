# Training: Rigister Globals

老版本PHP有个特性，就是会直接将URL里的GET参数变成一个变量名。举例而言，在URL里有`?key=value`，那么PHP中直接可以用`$key`，其值为`'value'`。

如果知道这一点，并且做好对于未初始化变量的处理，本来是不会有什么问题的，问题就出在未初始化变量上，所以PHP后来取消了这个特性。

为了达到老版本同样的效果，题目的PHP里增加了一句：

```php
foreach ($_GET as $k => $v) { $$k = $v; }
```

这就导致所有的未初始化变量成为用户可控变量，存在被利用的风险。

本题中，如果没有POST合法的password和username或完全没有POST，则`$login`不会被初始化，成为可控变量。后面又根据`$login`里的值判断是否为管理员，利用这一点可以过题。
