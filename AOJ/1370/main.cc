#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;

char s1[4005], s2[4005];
size_t len1, len2;
unordered_set<unsigned long long> set;
unsigned long long anagram;

constexpr unsigned long long seed = 772002;
unsigned long long learnhash(int occur[26]) {
    unsigned long long hash = 0;
    for (int i = 0; i != 26; ++i)
        (hash += occur[i]) *= seed;
    return hash;
}

int main() {
    scanf("%s%s", s1, s2);
    len1 = strlen(s1); len2 = strlen(s2);
    int maxlen = min(len1, len2);
    for (int len = 1; len <= maxlen; ++len) {
        int occur[26] = {0}; set.clear();
        for (int i = 0; i != len; ++i) ++occur[s1[i] - 'a'];
        for (int i = len; i <= len1; ++i) {
            set.insert(learnhash(occur));
            --occur[s1[i - len] - 'a'];
            ++occur[s1[i] - 'a'];
        }
        memset(occur, 0, sizeof occur);
        for (int i = 0; i != len; ++i) ++occur[s2[i] - 'a'];
        for (int i = len; i <= len2; ++i) {
            if (set.count(learnhash(occur)))
                anagram = len;
            --occur[s2[i - len] - 'a'];
            ++occur[s2[i] - 'a'];
        }
    }
    printf("%llu\n", anagram);
    return 0;
}
