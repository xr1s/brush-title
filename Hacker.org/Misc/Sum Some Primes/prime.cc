#include <iostream>
#include <bitset>
#include <list>
using namespace std;

int n = 1000000000;
bitset<1000000000> isprime;
list<int> prime;
int pnum;
long long sum;

int main() {
    isprime.set();
    isprime.reset(0);
    isprime.reset(1);
    for (int p = 2; p != n; ++p) {
        if (isprime.test(p)) {
            prime.push_back(p);
            if (++pnum > 50000000) break;
            if (pnum > 49999950) sum += p;
        }
        for (int j: prime) {
            if (p * j >= n) break;
            isprime.reset(p * j);
            if (p % j == 0) break;
        }
    }
    cout << sum << endl;
    return 0;
}
