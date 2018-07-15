#include <algorithm>
#include <queue>

template <size_t Charset>
class AhoCorasickAutomaton {
 public:
  AhoCorasickAutomaton();
  ~AhoCorasickAutomaton();

  template <typename InputIterator>
  void insert(InputIterator, InputIterator);
  template <typename InputIterator>
  size_t query(InputIterator, InputIterator);

 private:
  void rebuild_();

  AhoCorasickAutomaton *success[Charset];
  AhoCorasickAutomaton *failure;
  size_t count;
};

template <size_t Charset>
AhoCorasickAutomaton<Charset>::AhoCorasickAutomaton()
    : failure(NULL), count(0) {
  typedef AhoCorasickAutomaton ACA;
  std::fill(this->success, this->success + Charset, (ACA *)NULL);
}

template <size_t Charset>
AhoCorasickAutomaton<Charset>::~AhoCorasickAutomaton() {
  for (size_t i = 0; i != Charset; ++i) delete this->success[i];
}

template <size_t Charset> template <typename InputIterator> void
AhoCorasickAutomaton<Charset>::insert(InputIterator s, InputIterator t) {
  typedef AhoCorasickAutomaton ACA;
  this->failure = NULL;
  ACA *p = this;
  while (s != t) {
    if (p->success[*s] == NULL)
      p->success[*s] = new ACA;
    p = p->success[*s++];
  }
  ++p->count;
}

template <size_t Charset> template <typename InputIterator> size_t
AhoCorasickAutomaton<Charset>::query(InputIterator s, InputIterator t) {
  typedef AhoCorasickAutomaton ACA;
  if (this->failure == NULL) this->rebuild_();
  size_t match = 0;
  for (ACA *p = this; s != t; ++s) {
    while (p->success[*s] == NULL)
      if ((p = p->failure) == this) break;
    if (p->success[*s]) p = p->success[*s];
    for (ACA *q = p; q != this; q = q->failure) {
      match += q->count;
      q->count = 0;
    }
  }
  return match;
}

template <size_t Charset> void
AhoCorasickAutomaton<Charset>::rebuild_() {
  typedef AhoCorasickAutomaton ACA;
  std::queue<ACA *> q;
  this->failure = this;
  for (size_t i = 0; i != Charset; ++i)
    if (this->success[i] != NULL) {
      this->success[i]->failure = this;
      q.push(this->success[i]);
    }
  while (!q.empty()) {
    ACA *p = q.front(); q.pop();
    for (size_t i = 0; i != Charset; ++i)
      if (p->success[i] != NULL) {
        q.push(p->success[i]);
        ACA *fail = p->failure;
        while (fail->success[i] == NULL)
          if ((fail = fail->failure) == this) break;
        if (fail->success[i])
          fail = fail->success[i];
        p->success[i]->failure = fail;
      }
  }
}

#include <cstdio>
#include <cstring>
using namespace std;

int T, N;
char text[1000005];

int main() {
  for (scanf("%d", &T); T; --T) {
    AhoCorasickAutomaton<26> ac;
    for (scanf("%d", &N); N; --N) {
      scanf("%s", text); size_t len = strlen(text);
      for (size_t i = 0; i != len; ++i) text[i] -= 'a';
      ac.insert(text, text + len);
    }
    scanf("%s", text); size_t len = strlen(text);
    for (size_t i = 0; i != len; ++i) text[i] -= 'a';
    printf("%d\n", (int)ac.query(text, text + len));
  }
}
