# Execution Style

直接提取出灰度bytes在某些地方有明显的WIN32 API痕迹。`strings`命令因为png压缩过所以没有明显的字符痕迹。

直接保存用file检查，结果是一个PE程序，跑一下可以解压出一个perl程序，跑一下输出一个python程序，跑一下可以输出一段乱码。

好吧，是Hacker VM的程序，跑一下可以输出答案。
