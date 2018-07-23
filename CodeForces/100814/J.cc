#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int T;
char inst[128][128];
string A;

string gen(const string &s, int left = 0) {
    long len = s.length();
    string g;
    if (left && len & 1) g += s.front();
    for (int i = left && len & 1; i + 1 < len; i += 2)
        g += inst[s[i]][s[i + 1]];
    if (!left && len & 1) g += s.back();
    return g;
}

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool dfs(const string &now, int turn) {
    if (now.length() == 1)
        return is_vowel(now[0]);
    if (turn) {
        bool lose = dfs(gen(now), turn ^ 1);
        if (now.length() & 1)
            lose &= dfs(gen(now, 1), turn ^ 1);
        return lose;
    } else {
        bool win = dfs(gen(now), turn ^ 1);
        if (now.length() & 1)
            win |= dfs(gen(now, 1), turn ^ 1);
        return win;
    }
}

int main() {
    for (scanf("%d", &T); T; --T) {
        for (int i = 'a'; i <= 'z'; ++i)
            for (int j = 'a'; j <= 'z'; ++j)
                while (!isalpha(inst[i][j] = getchar()));
        cin >> A;
        puts(dfs(A, 0) ? "Salah" : "Marzo");
    }
    return 0;
}
