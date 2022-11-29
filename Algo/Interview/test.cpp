#include <iostream>
int functionTest(unsigned int n) {
  unsigned int c = 0;
  for (c = 0; n; ++c) {
    n&=(n-1);
  std::cout << n << std::endl;

  }
  return c;
}

int main() {
  unsigned int n;
  std::cin >> n;
  std::cout << functionTest(n) << std::endl;
  return 0;
}