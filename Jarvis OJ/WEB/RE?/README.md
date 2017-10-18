# RE?

文件下过来`file`一看，的确是个elf链接文件。首先`strings`一波，看了一下大概有哪些函数，有个很显眼的`getflag`函数，还有个可能有用的`help_me`函数。

直接`objdump`反汇编提示格式不对，试图自己写个程序链接上去也失败了。

想到udf应该是MySQL的UDF，试着在MySQL里加载成功了，`SELECT`了一句`getflag() `就出flag了。
