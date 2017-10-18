# Webshell分析

先`strings`一波，找flag，发现在请求一个webshell的时候出现的路径里包含flag。

用wireshark过滤`http contains flag`，找到请求，追踪HTTP流，找到响应。

响应中有一串base64编码的信息，解码之后是一个url，直接请求，一个二维码，解码即可。
