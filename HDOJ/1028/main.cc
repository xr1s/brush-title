#include <vector>
#include <iostream>
using namespace std;

template <int m, int n> struct minimum {
    const static int value = m < n ? m : n;
};

template <int s, int t> struct helper {
    enum {
        value = helper<s, t - 1>::value
            + helper<s - t, minimum<s - t, t>::value>::value
    };
};

template <int t> struct helper<1, t> {
    enum {
        value = 1
    };
};

template <int s> struct helper<s, 1> {
    enum {
        value = 1
    };
};

template <> struct helper<1, 1> {
    enum {
        value = 1
    };
};

template <int t> struct helper<0, t> {
    enum {
        value = 1
    };
};

template <int s> struct helper<s, 0> {
    enum {
        value = 1
    };
};

template <> struct helper<0, 0> {
    enum {
        value = 1
    };
};

template <int n> struct equation {
    enum {
        value = helper<n, n>::value
    };
    static void put(vector<int> &v) {
        equation<n - 1>::put(v);
        v.push_back(value);
    }
};

template <> struct equation<0> {
    enum {
        value = 1
    };
    static void put(vector<int> &v) {
        v.push_back(value);
    }
};

int main() {
    int n;
    vector<int> answer;
    equation<120>::put(answer);
    while (cin >> n)
        cout << answer[n] << endl;
    return 0;
}
