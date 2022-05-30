// Smart Pointer View.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <memory>

using namespace std;
// Shared pointer
class myShared {
public:
    myShared() {
        cout << "Constructor" << endl;
    }
    ~myShared() {
        cout << "Destructor" << endl;
    }
};

//Pointers storage address
void shared1();
void weak2();

int main()
{
    // Improved security and is a replacement of auto_ptr
    // Only one unique_ptr can be used
    // Once it's destroyed the resource is automatically claimed
    // Any atttempts to make a copy of unique will cause compile-time error
    unique_ptr<int>unPtr1 = make_unique<int>(30);
    cout << unPtr1 << endl;
    cout << *unPtr1 << endl;
    shared1();
    weak2();
}

void shared1() {
    //shared_ptr is container for raw pointers referencing and maintains reference counts
    // Storing numbers of references, pointers and handles resources like objects,
    // block memory, disk space and other resources.
    // Couting how many shared files
    shared_ptr<myShared>shPtr1 = make_shared<myShared>();
    cout << "Shared cout: " << shPtr1.use_count() << endl;
    shared_ptr<myShared>shPtr2 = shPtr1;
    cout << "Shared cout: " << shPtr1.use_count() << endl;
}

void weak2() {
    // Provides access to an object
    // Destruction of weak_ptr has no effect on shared_ptrs or copies
    // Breaks circular references between shared_ptr
    weak_ptr<int> wkPtr3;
    {
        shared_ptr<int>shPtr3 = make_shared<int>(10);
        wkPtr3 = shPtr3;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
