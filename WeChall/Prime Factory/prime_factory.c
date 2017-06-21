#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define million (1000000)
bool isprime[million << 1];
int prime[million], pnum;

int digit_sum(int x) {
	int sum = 0;
	do sum += x % 10;
	while (x /= 10);
	return sum;
}

void euler_sieve(int n) {
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i != n; ++i) {
		if (isprime[i]) prime[pnum++] = i;
		for (int j = 0; j != pnum; ++j) {
			if (i * prime[j] >= n) break;
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
	int count = 0;
	euler_sieve(million * 2);
	for (int i = 0; i != pnum; ++i)
		if (prime[i] > million && isprime[digit_sum(prime[i])]) {
			printf("%d", prime[i]);
			if (++count == 2) break;
		}
	putchar('\n');
	return 0;
}

