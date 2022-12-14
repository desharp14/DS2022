#include <iostream>
#include <vector>
#include <ctime>
#include "BinarySearchTree.h"
using namespace std;
template <typename Comparable>

void BSTSorting(vector<Comparable> &_arr, int _mode = 0)
{
  BinarySearchTree<Comparable> bst;
  int start, finish;
  int time = 0;
  //当 _mode = 0 时, 不乱序
  if(_mode == 0)
  {
    start = clock();
    for(int i = 0; i <_arr.size(); ++i)
    {
      bst.insert(_arr[i]);
    }
    finish = clock();
    time = (double)(finish-start)/CLOCKS_PER_SEC;
  }
  //当 _mode = 1 时, 先对数组 _arr 乱序后再排序。
  else if(_mode == 1)
  {
    for(int j = 0; j < 100; ++j)
    {
      bst.makeEmpty();
      start = clock();
      for(int i = _arr.size()-1; i >= 1; --i)
      {
        int k = rand()%i;
        Comparable t = _arr[k];
        _arr[k] = _arr[i];
        _arr[i] = t;
      }
      for(int i = 0; i < _arr.size(); ++i)
      {
        bst.insert(_arr[i]);
      }
      finish = clock();
      time += (double)(finish-start)/CLOCKS_PER_SEC;
    }
  }

  cout << "BStSorting time: " << time << "s" << endl;
}

int main()
{
    int t, mode;
    cout << "Enter Array:"; cin >> t;
    cout << "Enter mode:"; cin >> mode;
    if(mode!=0 && mode !=1)
    {
        cout << "Enter 0 or 1.\n";
    }
    vector<int> _arr={};
    for(int t = 0; t<=1; t++)
    {
        _arr.push_back(t);
    }
    BSTSorting(_arr,mode);
        return 0;
}
