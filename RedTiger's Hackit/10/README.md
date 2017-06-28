# level 10

最后一关，一上来只有一个buttom，吓得我看了一下开发者工具的网络项。然后发现了源码里有俩hidden的input标签，这个name叫login的那个标签，value里有一串长得特别像base64的东西。

那就是base64，解码看到一串特别像php serialize的东西。

那就是php serialize，我猜我找到注入点了。`unserialize`后得到一个

```php
Array
(
    [username] => Monkey
    [password] => 0815password
)
```

好了，重新构造一个再`serialize`再`base64_encode`就好了。

然后试了万能密码，登录失败。喵喵喵？

似乎没有回显，我没办法bool和报错注入了，试试时间？

没用！

我擦？

xjb跑了几个密码也不行。去搜了题解表示只要把password设置为`TRUE`就可以过关。但是`TRUE`在php接到字符串里是`"1"`，为什么我直接用`"1"`却没有结果，存疑。

