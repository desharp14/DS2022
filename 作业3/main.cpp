#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include "AvlTree.h"

using namespace std;

int main() {

    clock_t start, finish;

    //When k <= log (n)
    AvlTree<int> T0;
    vector<int> vec0 {100, 890, 33, 0};
    for(int i = 0; i < vec0.size(); ++i)
    {
        T0.insert(vec0[i]);
        cout << vec0[i] << " ";
    }
    cout << endl;
    T0.printTree();
    cout << endl;

    //When k = n
    AvlTree<int> T1;
    vector<int> vec1 {1000, 10000, 100000, 1000000};

    int count1 = 0;
    while(count1 < vec1.size())
    {
        int n = vec1[count1];
        int k = n;


        for(size_t j{1}; j <= n; ++j)
        {
            T1.insert(j);
        }
        start = clock();
        T1.printElement(1,k);
        finish = clock();

        cout << "n = " << n << endl;
        cout << "Runtime: " << double(finish-start) / CLOCKS_PER_SEC << " s" << endl;

        count1++;
    }

    cout << endl;

    //When k = log(n)
    AvlTree<int> T2;
    vector<int> vec2 {int(pow(2,14)), int(pow(2,16)), int(pow(2,18)), int(pow(2,20))};

    int count2 = 0;
    while(count2 < vec2.size())
    {
        int n = vec2[count2];
        int k = log2(n);


        for(size_t j{0}; j <= n; ++j)
        {
            T2.insert(j);
        }

        start = clock();
        T2.printElement(n,n + k - 1);
        finish = clock();

        cout << "n =" << n << endl;
        cout << "Runtime: " << (finish-start) / CLOCKS_PER_SEC << " s" << endl;

        count2++;
    }


    return 0;
}