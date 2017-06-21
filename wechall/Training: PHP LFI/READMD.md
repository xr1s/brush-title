# Training: PHP LFI

告诉你有LFI，以及需要被LFI的文件，那么看几个例子就知道怎么搞了。

因为include有NUL绕过的漏洞，所以即使代码中添加了后缀名也没用，只需要%00即可绕过。

