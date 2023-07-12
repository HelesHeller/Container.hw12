#include <iostream>
#include <windows.h>

#include "Array.h"

using namespace std;

int main() {

    Array<int> arr;

    cout << "Created new object arr with constructor by default: " << endl << endl;

    cout << "IsEmpty: " << arr.IsEmpty() << endl;
    cout << "GetSize: " << arr.GetSize() << endl;
    cout << "GetCapacity: " << arr.GetCapacity() << endl;
    cout << "GetUpperBound: " << arr.GetUpperBound() << endl;
    cout << "GetData: " << arr.GetData() << endl;

   



    arr.SetSize(5);

    cout << "Calling for method SetSize(5) to set object's size to 5: " << endl << endl;

    cout << "SetSize: " << arr.GetSize() << endl;
    cout << "GetUpperBound: " << arr.GetUpperBound() << endl << endl;

    for (int i = 0; i < arr.GetSize(); i++)
        arr.SetAt(i, i + 1);

    cout << "Calling for method SetAt(i, i + 1), to initiate object arr with values that equals i + 1: " << endl << endl;

    cout << "GetAt: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr.GetAt(i) << " ";
    cout << endl;

   



    arr.FreeExtra();

    cout << "Object arr after calling FreeExtra() method (method is used for errasing memory that used above last index of array) :" << endl << endl;

    cout << "GetCapacity: " << arr.GetCapacity() << endl;

   


    arr.RemoveAll();

    cout << "Object arr after calling RemoveAll() method (method is used for setting all object's values of fields to zero and pointer to nullptr position) :" << endl << endl;

    cout << "GetSize: " << arr.GetSize() << endl;
    cout << "GetCapacity: " << arr.GetCapacity() << endl;

    



    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    cout << "Calling for methods: Add(10), Add(20), Add(30) for created object to set it size++, also making its recapacity and set values of 10, 20, 30 at position of 'size' each time method called: " << endl << endl;

    cout << "GetAt: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr.GetAt(i) << " ";
    cout << endl;

    



    Array<int> arr2;
    arr2.Add(40);
    arr2.Add(50);

    cout << "Creating new Object arr2 with default constructructor and calling for methods Add(40), Add(50): " << endl << endl;

    cout << "GetSize: " << arr2.GetSize() << endl;
    cout << "GetAt: ";
    for (int i = 0; i < arr2.GetSize(); i++)
        cout << arr2.GetAt(i) << " ";
    cout << endl;

    



    arr.Append(arr2);

    cout << "Using method Append for object arr to add object's arr2 elements to the end of arr: " << endl << endl;

    cout << "GetSize: " << arr.GetSize() << endl;
    cout << "GetAt: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr.GetAt(i) << " ";
    cout << endl;

    



    arr.InsertAt(2, 99);

    cout << "Calling method InsertAt(2, 99) for object arr to add element with value of 99 in 2nd position: " << endl;

    cout << "GetSize: " << arr.GetSize() << endl;
    cout << "GetAt: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr.GetAt(i) << " ";
    cout << endl;

    



    arr.RemoveAt(3);

    cout << "Calling for method RemoveAt(3) for object arr to remove its element from 3rd position: " << endl;

    cout << "GetSize: " << arr.GetSize() << endl;
    cout << "GetAt: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr.GetAt(i) << " ";
    cout << endl;

    

    return 0;
}
