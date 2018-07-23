#include <cstdio>
using namespace std;

int M, sign[25], N;
int music[10005];
long long answer;

int note_id(char note[]) {
    int id = (note[0] - 'A') * 3;
    if (note[1] == '\0') id += 1;
    else if (note[1] == '#') id += 2;
    return id;
}

int main() {
    scanf("%d", &M);
    for (int i = 0; i != M; ++i)
        for (int j = 0; j != 7; ++j) {
            char note[3]; scanf("%s", note);
            int id = note_id(note);
            sign[i] |= 1 << id;
        }
    scanf("%d", &N);
    for (int i = 0; i != N; ++i) {
        char note[3]; scanf("%s", note);
        music[i] = note_id(note);
    }
    for (int current = 0; current != N; ) {
        int max_forward = 0;
        for (int i = 0; i != M; ++i)
            for (int j = 0; j != M; ++j) {
                int forward = current;
                while (sign[i] & 1 << music[forward]
                        || sign[j] & 1 << music[forward])
                    if (forward != N) ++forward; else break;
                if (forward > max_forward) max_forward = forward;
            }
        current = max_forward;
        ++answer;
    }
    printf("%lld\n", answer);
    return 0;
}

