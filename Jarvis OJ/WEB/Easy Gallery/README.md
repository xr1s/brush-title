# Easy Gallery

这题出题人是傻逼。

文件上传是真的，文件包含是假的。

文件包含逻辑是

```php
$file = fopen($_GET['page']);
$content = fread($file);
if (preg_match('#<?php#s', $content))
    die('你不允许做这个');
if (preg_match('#<script +language="php">#', $content))
    die($flag);
```

MDZZ，只要用大写就没有flag。
