#include <iostream>
#include "list342.h"
using namespace std;

int main()
{
    // Test 1 - Runs initializes Blank List and Inserts 10 Integers
    try {
        List342<int> int1;
        for (int i = 0; i < 10; i++) {
            int1.Insert(new int(i));
        }
        cout << int1.toString();
        cout << int1.Size() << endl;
        cout << int1 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    List342<int> int1;
    for (int i = 0; i < 10; i++) {
        int1.Insert(new int(i));
    }

    // Test 2 - Runs copy constructor on int1
    try {
        List342<int> int2 = int1;
        cout << int2.toString();
        cout << int2.Size() << endl;
        cout << int2 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    List342<int> int2 = int1;
    int x = 0;

    // Test 3 - Runs remove method on int2
    try {
        for (int i = 5; i < 10; i++) {
            int2.Remove(i, x);
        }
        cout << int2.toString();
        cout << int2.Size() << endl;
        cout << int2 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    x = 0;
    for (int i = 5; i < 10; i++) {
        int2.Remove(i, x);
    }

    // Test 4 - Runs Peek method on int1
    try {
        for (int i = 0; i < 10; i++) {
            int1.Peek(i, x);
            cout << x << endl;
        }
        cout << int1.toString();
        cout << int1.Size() << endl;
        cout << int1 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    // Test 5 - Runs DeleteList on int2
    try {
        int2.DeleteList();
        cout << int2.toString();
        cout << int2.Size() << endl;
        cout << int2 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    List342<int> int3;
    for (int i = 5; i < 15; i++) {
        int3.Insert(new int(i));
    }

    // Test 6 - Runs Merge on int3 using int1
    try {
        int3.Merge(int1);
        cout << int3.toString();
        cout << int3.Size() << endl;
        cout << int3 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        int1.Insert(new int(i));
    }

    // Test 7 - Runs Assignment Operator on int2 using int1
    try {
        int2 = int1;
        cout << int2.toString();
        cout << int2.Size() << endl;
        cout << int2 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    int2 = int1;

    // Test 8 - Runs Assignment and Addition Operator on int4 using int2 and int 3
    try {
        List342<int> int4 = int2 + int3;
        cout << int4.toString();
        cout << int4.Size() << endl;
        cout << int4 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    List342<int> int4 = int2 + int3;

    // Test 9 - Runs += operator on int1 using int3
    try {
        int1 += int3;
        cout << int1.toString();
        cout << int1.Size() << endl;
        cout << int1 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    int1 += int3;

    // Test 10 - Runs the equals operator on int1 and int4
    try {
        if (int1 == int4) {
            cout << "Equal" << endl;
        } else {
            cout << "Not Equal" << endl;
            cerr << "This should not be printed" << endl;
        }
        cout << int1.toString();
        cout << int1.Size() << endl;
        cout << int1 << endl;
        cout << int4.toString() << endl;
        cout << int4.Size() << endl;
        cout << int4 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    // Test 11 - Runs the not equals operator on int2 and int3
    try {
        if (int2 != int3) {
            cout << "Not Equal" << endl;
        }
        else {
            cout << "Equal" << endl;
            cerr << "This should not be printed" << endl;
        }
        cout << int2.toString();
        cout << int2.Size() << endl;
        cout << int2 << endl;
        cout << int3.toString();
        cout << int3.Size() << endl;
        cout << int3 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    try {
        List342<int> int5;
        int5.BuildList("main.txt");
        cout << int5.toString();
        cout << int5.Size() << endl;
        cout << int5 << endl;
    } catch (exception e) {
        cout << e.what();
        return 1;
    }

    return 0;

}