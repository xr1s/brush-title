# level 3

随便点了几下userdetails，并没有任何可以获取到的信息。

在form里注入也没什么效果，至少ORDER BY没有任何效果。根据题目提示报错注入，没有任何回显。

注意到GET又有了参数，看起来像是base64，解码一下，两个用户分别得到不同的一串数字。不是很懂这数字，在数字后加了payload重新编码注入无效。

注意到提示说报错，于是改了一下GET参数，用非法的base64编码，没有报错。然后试了试`user[]`，成功报错。

> Warning: preg\_match() expects parameter 2 to be string, array given in /var/www/html/hackit/urlcrypt.inc on line 25

爆出了文件名，去检查一下这个文件，直接泄漏了源码。看一下源码可以得到，有一对加密和解密的函数。给那两串数字解了密，发现就是用户名。

于是撰写payload...xjb打了一句sql，加密后传过去成功报错（其实就是本渣写错SQL了）

检查ORDER BY，有7列。试着打了一下，分别是第二列Username，第六列First name，第七列Name，第5列ICQ，第4列Email。总之拿到了回显项。

然后就可以直接爆密码了。
