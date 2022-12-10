#include <iostream>

#include <vector>

#include <ctime>

#include <cmath>

#include "Graph.h"

using namespace std;

int main() {

  vector < char > vertex = {
    'A',
    'B',
    'C',
    'D'
  };
  vector < Edge > list;
  list.push_back(Edge {
    0,
    1,
    2
  });
  list.push_back(Edge {
    0,
    2,
    1
  });
  list.push_back(Edge {
    0,
    2,
    2
  });
  list.push_back(Edge {
    2,
    2,
    4
  });
  list.push_back(Edge {
    3,
    2,
    4
  });

  vector < Edge > list1 = {
    Edge {
      0,
      1
    },
    Edge {
      0,
      3
    },
    Edge {
      2,
      1
    },
    Edge {
      2,
      3
    }
  };

  cout << "Test adj_mat: " << endl;
  Graph < char > G1(store_type::adj_mat, vertex, list);
  cout << "- Vertexes:" << endl;
  G1.listVertexes();
  cout << "- Edges:" << endl;
  G1.listEdges();
  cout << endl;

  cout << "Test adj_list: " << endl;
  Graph < char > G2(store_type::adj_list, vertex, list);
  cout << "- Vertexes:" << endl;
  G2.listVertexes();
  cout << "- Edges:" << endl;
  G2.listEdges();
  cout << endl;

  cout << "Test undirected graph: " << endl;
  Graph < char > G3(store_type::adj_mat, vertex, list1, false);
  cout << "- Vertexes:" << endl;
  G3.listVertexes();
  cout << "- Edges:" << endl;
  G3.listEdges();
  cout << endl;

  return 0;
}