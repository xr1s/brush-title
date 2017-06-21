# Choose your Path

服务器上题目目录在/home/level/10

题目给了个C文件，本以为是pwn题，结果是一道逻辑漏洞。还有一个可执行文件，一个sh大概是用来编译，一个solution.txt。查看权限，solution.txt主人是root，组属于level10，都只有读权限。

观察源码，使用了一个`popen`函数，查man手册

> The popen() function opens a process by creating a pipe, forking, and invoking the shell. Since a pipe is by definition unidirectional, the type argument may specify only reading or writing, not both; the resulting stream is correspondingly read-only or write-only.

大意是传入一个shell命令，popen会fork一个进程执行这段命令，然后把stdout输出到管道，返回这个管道的文件指针。

源码中，直接将第二个参数argv[1]作为文件名拼接到`wc`命令中计算词数，然后从输出中读取数字。既然是直接拼接命令，我就在“文件名”里加点命令。由于`popen`只会把stdout输出到临时打开的文件里，我们可以往stderr写东西，直接输出到屏幕。

