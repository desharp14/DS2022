#include <iostream>

#include <vector>

#include <ctime>

#include <cmath>

#include <random>

#include <cstdlib>

#include <iomanip>

#include <string>

#include "Graph.h"

using namespace std;

Graph < int > GenGraph(int V, int E) {
  default_random_engine e;
  uniform_int_distribution < int > u1(0, V - 1);
  uniform_int_distribution < int > u2(-10, 10);
  e.seed(time(0));
  vector < Edge > EL {};
  vector < int > vertex {};

  for (int i = 0; i < V; ++i) {
    vertex.push_back(i);
  }

  for (int i = 0; i < E; ++i) {
    int u = u1(e), v = u1(e), w = u2(e);
    if (u != v)
      EL.push_back(Edge {
        u,
        v,
        w
      });
    else
      i--;
  }

  Graph < int > G(store_type::adj_list, vertex, EL);
  return G;
}

void Test(vector < int > N, vector < int > E) {
  int n = N.size(), m = E.size();
  clock_t start, end;
  double time = 0.0;
  double * Data = new double[n * m];
  cout << left << setw(12) << "|V|";

  for (int j = 0; j < n; ++j)
    cout << left << setw(12) << N[j] << flush;
  cout << endl;

  for (int i = 0; i < m; ++i) {
    string s = "|E|= ";
    s += to_string(E[i]);
    s += "*|V|";
    cout << left << setw(12) << s << flush;
    for (int j = 0; j < m; ++j) {
      auto G = GenGraph(N[j], N[j] * E[i]);
      start = clock();
      G.BELLMAN_FORD(0, false);
      end = clock();
      time = (double)(end - start) / CLOCKS_PER_SEC;
      Data[n * i + j] = time;
      cout << left << setw(12) << time << flush;
    }
    cout << endl;
  }
  delete[] Data;
}

int main() {
  vector < char > V1 = {
    's',
    't',
    'x',
    'y',
    'z'
  };
  vector < Edge > EL1 = {
    Edge {
      0,
      1,
      6
    },
    Edge {
      0,
      3,
      7
    },
    Edge {
      1,
      2,
      5
    },
    Edge {
      1,
      3,
      8
    },
    Edge {
      1,
      4,
      -4
    },
    Edge {
      2,
      1,
      -2
    },
    Edge {
      3,
      2,
      -3
    },
    Edge {
      4,
      0,
      2
    },
    Edge {
      4,
      2,
      7
    },
  };

  Graph < char > G1(store_type::adj_list, V1, EL1);
  cout << "Bellman Ford: " << endl;
  G1.BELLMAN_FORD(0, true);
  G1.addEdge(Edge {
    4,
    1,
    2
  });
  G1.BELLMAN_FORD(0, true);
  cout << endl;

  cout << "Test complexity(s): " << endl;

  vector < int > TestN = {
    500,
    1000,
    2000,
    4000
  };
  vector < int > TestE = {
    2,
    4,
    8,
    16
  };
  Test(TestN, TestE);

  return 0;
}