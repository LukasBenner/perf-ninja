
#include <array>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
struct S {
    long long l; // 8B
    double d;    // 8B
    int i;       // 4B
    short s;     // 2B
    bool b;      // 1B
    // padding   // 1B

  bool operator<(const S &s) const { return this->i < s.i; }
};
static_assert(sizeof(S) == 24);

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
