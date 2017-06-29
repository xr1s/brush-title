# Stegano Attachment

这里下图片就没意思了，每个Session的图片是不一样的。

图片下载过来之后，`exif`没信息，`strings`一跑，最后出现了一行solution.txt，很明显了。用`binwalk -e`直接提取即可。
