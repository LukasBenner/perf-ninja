
#include "solution.h"
#include <random>

S create_entry(int first_value, int second_value) {
  S entry;

  entry.i = static_cast<char>(first_value); // could be char due to 0 <= maxRandom < 100
  entry.s = static_cast<char>(second_value); // could be char due to 0 <= maxRandom < 100
  entry.l = static_cast<short>(first_value * second_value); // multipl of two char should fit in a short
  entry.d = static_cast<float>(first_value) / maxRandom;  // doublr to flat, loosing precision is fine I guess
  entry.b = first_value < second_value;

  return entry;
}

void init(std::array<S, N> &arr) {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(minRandom, maxRandom - 1);

  for (int i = 0; i < N; i++) {
    int random_int1 = distribution(generator);
    int random_int2 = distribution(generator);

    arr[i] = create_entry(random_int1, random_int2);
  }
}
