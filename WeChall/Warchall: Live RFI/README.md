# Warchall: Live RFI

你根本就不是RFI！

我试了一下http协议，发现可以请求localhost，返回的和直接访问warchall.net的返回一样，所以确实存在rfi。

然后……试了一下php伪协议，`php://filter/convert.base64-encode/resource=index.php`成功泄漏源码，这个的危害还不是很大。可是接下去我抱着试试看的心理curl了一下php://input，post了phpinfo上去。

好小子，直接执行了，这就没有悬念了。

`ls`之后发现solution就在当前目录，直接源码泄漏也是可以的。
