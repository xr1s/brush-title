# Didactic RGB

Do you see the single-color image below?

![](https://raw.githubusercontent.com/xr1s/brush-title/master/Hacker.org/didactrgb.png)

This image is actually only 1 pixel by 1 pixel, and is stretched out here so you can see it. What can such an image represent? Pixels are commonly composed on a computer of red, green, and blue components. Each component can be any number of bits -- the more bits, the more detail an image can reflect. A common number of bits per color is eight. If we look at this single pixel, we get three colors of eight bits each, which equals 24 bits of data total. What to do with those 24 bits? For this challenge, express it as a decimal integer. That is your answer. (In other words, the answer looks something like '12345678'. These are all 24 bits considered as one single number in decimal.)

## 翻译

你能看见下面的单色图片吗？

这张图实际上只有1×1字节大小，被拉伸到了这么大。这么一张图片能表达什么呢？计算机中，每个像素通常由RGB三种原色组成，每种颜色可以是任意位——位数越高，一个像素的颜色信息更丰富。通常来说，每个像素每个颜色都有8位，也就是每个像素有24位信息。我们拿这24位信息干什么呢？在这个挑战里，把它表现为一个十进制的数字，这就是你的答案。

## 解题报告

尝试过开发者工具里直接取色，但是可能因为渲染的原因（？）所以直接取来的颜色不是正确答案，所以用下载了过来，用Pillow取了一下颜色。

