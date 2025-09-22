#include <iostream>
using namespace std;

int factorial_tail(int n, int result = 1) {
    if (n == 0){
        return result;
    }
    return factorial_tail(n - 1, n * result);
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << ": " << factorial_tail(n) << endl;
    return 0;
}

// def factorial_tail(n,result = 1):
//   if(n == 0):
//     return result
//   return factorial_tail(n - 1,n*result)