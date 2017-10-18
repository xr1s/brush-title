# 神盾局的秘密

一进去一张图片，看了一下源码，看到是`<img src="showimg.php?img=c2hpZWxkLmpwZw==" width="100%"/>`形式。很明显的文件包含，加了个base64。

于是先include一下showimg.php和index.php，从showimg里看到过滤了pctf和一些指定目录的字符，index.php里有个`unserialize`函数调用，并包含了shield.php，继续包含shield.php，看到有个Shield类，有个`__construct`魔术方法，配合前面的`unserialize`，知道要干什么了。虽然说flag在pctf.php里，但是访问后有个（显然是）假flag，而且有个过滤，先无视这个flag。

然后从index.php传入GET参数class为`serialize`和`urlencode`后的`Shield`类，文件名指向pctf.php，直接就可以了。
