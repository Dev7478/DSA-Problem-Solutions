#include <iostream>
using namespace std;

int fibonacci_tail(int n, int a = 0, int b = 1) {
  if (n == 0)
    return a;
  if (n == 1)
    return b;
  return fibonacci_tail(n - 1, b, a + b);
}

int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;
  cout << "fib (" << n << ") = " << fibonacci_tail(n) << " ";
  return 0;
}