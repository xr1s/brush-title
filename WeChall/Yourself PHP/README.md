# Yourself PHP

看了一下源码，username被`htmlspeciachars`了，不报希望。

另一个存在可能可以输入的地方是`<form>`的`action`处，用了`$_SERVER['PHP_SELF']`，查了一下资料，在url里添加payload就可以了。
