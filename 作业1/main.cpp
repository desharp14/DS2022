#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
    DoubleLinkedList<int> list;
    DoubleLinkedList<int>::iterator iter;
    for(int i = 1; i <= 5; ++i)
    {
        list.push_back(i);
    }

    PrintList(list);
    iter = find(list,3);
    list.erase(iter);
    PrintList(list);
    iter = find(list,3);

    return 0;

}
