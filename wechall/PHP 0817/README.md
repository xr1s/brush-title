# PHP 0817

题目再次说明了有LFI漏洞，需要被LFI的也说明了。

看代码，有个`switch ($which)`判断`$which`是否为0, 1, 2，注意`switch`是弱类型判断，利用这个直接传入solution即可，PHP中`'solution' == 0`。

