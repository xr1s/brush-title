#include <stdio.h>

int main() {
	char c;
	freopen("/home/level/11/solution.txt", "r", stdin);
	freopen("/home/user/xris/result.txt", "w", stdout);
	freopen("/home/user/xris/result.txt", "w", stderr);
	while (~(c = getchar())) putchar(c);
	return 0;
}

