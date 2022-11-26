#include <iostream>

#include <vector>

#include <ctime>

#include <cmath>

#include "Sorting.h"

using namespace std;

vector < int > order(int n, double i) {
  //v为存放数据的数组
  vector < int > v;
  int range;
  int t;
  srand((unsigned int) time(0));

  if (i < 0.5) {
    range = n * sqrt(i);
    t = rand() % (n - 2 * range);
    for (int j = 1; j < t; j++) {
      v.push_back(j);
    }
    for (int j = t; j < t + range; ++j) {
      v.push_back(j + range);
    }
    for (int j = t + range; j < t + 2 * range; ++j) {
      v.push_back(j - range);
    }
    for (int j = t + 2 * range; j < n; ++j) {
      v.push_back(j);
    }
  } else {
    range = n * sqrt(1 - i);
    t = rand() % (n - range);
    for (int j = 1; j < t; j++) {
      v.push_back(n - j);
    }
    for (int j = t; j < t + range; j++) {
      v.push_back(n - j - range);
    }
    for (int j = t + range; j < t + 2 * range; j++) {
      v.push_back(n - j + range);
    }
    for (int j = t + 2 * range; j < n; j++) {
      v.push_back(n - j);
    }
  }
  return v;
}

int main() {
  //eff为效率
  vector < double > eff {
    0.01,
    0.1,
    0.9,
    0.99
  };
  vector < int > size {
    10000,
    100000,
    1000000
  };

  for (auto & n: size) {
    cout << "When n = " << n << "," << endl;
    for (auto & i: eff) {
      cout << "- efficiency: " << i << ", ";

      clock_t start1, finish1, start2, finish2;
      vector < int > v1 = order(n, i);
      start1 = clock();
      heapsort(v1);
      finish1 = clock();
      cout << "heaptime: " << (double)(finish1 - start1) / CLOCKS_PER_SEC << " s, ";

      vector < int > v2 = v1;
      start2 = clock();
      quicksort(v2);
      finish2 = clock();
      cout << "quicktime: " << (double)(finish2 - start2) / CLOCKS_PER_SEC << " s." << endl;
    }
    cout << endl;
  }

  return 0;

}