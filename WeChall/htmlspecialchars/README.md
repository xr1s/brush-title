# htmlspecialchars

没记错的话php的这个函数是没有漏洞的，只要使用正确。

看到html里使用了单引号，`htmlspecialchars`默认不过滤单引号，试了一下果然闭合了单引号，于是在这个函数第二个参数加上`ENT_QUOTES`就转义了单引号。
