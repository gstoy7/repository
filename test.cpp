// test_List.cpp
//
// Small test driver for our class List.

#include <iostream>
using namespace std;

#include "queue.h"

template <typename T>
void print(const Queue<T> & ls)
{
//    ls.test_print();
    for (const T & e : ls) cout << e << ' ';
    cout << endl;
}

int main()
{
    cout << "push_back: ";
    Queue<int> ls;
    ls.push(1);
    ls.push(2);
    print(ls);

    cout << "Current queue: ";
    print(ls);
    cout << endl;
    cout << "front: ";
    cout << ls.front() << endl;
    cout << "changing front of the list to 7..." << endl;
    ls.front() = 7;
    print(ls);
    
    cout << "Current queue: ";
    print (ls);
    cout << endl;
    cout << "Queue post pop on 1st element: ";
    ls.pop();
    print(ls);
    ls.pop();
    cout << "Queue post pop on other element: ";
    print(ls);
    ls.push(69);
    ls.push(70);
    ls.push(71);
    ls.push(72);
    cout << "Putting some numbers back into the queue: ";
    print(ls);

    int position = ls.search(75);
    cout << "75 is in position: " << position << endl;
    int pos2 = ls.search(69);
    cout << "69 is in position: " << pos2 << endl;    
   
    ls.clear();
    cout << "Clearing the queue: ";
    print(ls);
    return 0;
}

