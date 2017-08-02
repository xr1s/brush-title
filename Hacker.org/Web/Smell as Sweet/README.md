# Smell as Sweet

先拆包，里面就一个文件，是一个tcpdump文件。拿到WireShark分析可以得到一个html和几个png。

html里有段javascript是最终输出密码的，但是需要这几个图片才行，所以从数据包里提取png，当然是利用WireShark提，将图片按照下载下来的命名好后打开html即可。
