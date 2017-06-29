# PHP 0815

分析源码，非常短小，看得出来的比较危险的就是用了一个`in_array`函数，默认是弱类型比较，所以只需要`$show`的第一个字符`in_array`就会绕过检测。

修改为`in_array($show, $whitelist, TRUE)`，还是不行，但是提示我

> If you try to modify in\_array() you are on a good track. Sadly it stops the script from working :(

说明确实是弱类型的问题，并且本地检验了一下，确实无法通过三个最基本的123，因为是强类型了，所以`$show`作为字符串和`$whitelist`中的三个`int`自然不相容。

于是用`intval($show)`，直接提示wrong，再试试改`$whitelist`为字符串的Array，也不行。

看了眼题目，试了一下`intval()`，不行，又出现一个提示

> You can go shorter!

吃鲸。试了一下`(int)`，不行，第三个提示（我……）

> Correct, You got the official recommended solution, But: You can cast to integer with only 2 chars!

这大概是最后的提示了，让我懵逼一下还有什么鬼畜的骚操作。

过了三分钟。

查资料的时候突然想到一个骚操作，隐式类型转换，+0即可。
