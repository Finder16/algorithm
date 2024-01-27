#include <bits/stdc++.h>
using namespace std;

long long int a_power_n_mod_m(long long int a, long long int n,
                              long long int m) {
  long long int result = 1;
  a = a % m;

  while (n > 0) {
    if (n % 2 == 1) {
      result = (result * a) % m;
    }
    n = n >> 1;
    a = (a * a) % m;
  }

  return result;
}

int millerRabinTest(long long int num, int iteration) {
  if (num <= 1) {
    return 0;
  }
  if (num <= 3) {
    return 1;
  }
  if (num % 2 == 0) {
    return 0;
  }

  long long int r = 0, s = num - 1;
  while (s % 2 == 0) {
    s /= 2;
    r++;
  }

  for (int i = 0; i < iteration; i++) {
    long long int a = rand() % (num - 2) + 1;
    long long int x = a_power_n_mod_m(a, s, num);

    if (x == 1 || x == num - 1) {
      continue;
    }

    for (int j = 0; j < r - 1; j++) {
      x = a_power_n_mod_m(x, 2, num);
      if (x == num - 1) {
        break;
      }
    }

    if (x != num - 1) {
      return 0;
    }
  }

  return 1;
}

int isPrime(long long int num) {
  int iterations = 10;
  return millerRabinTest(num, iterations);
}

int main() {

  for (int num = 2; num <= 100000000; num++) {
    if (isPrime(num)) {
      cout << num << "\n";
    }
  }

  return 0;
}
