#include <iostream>
using namespace std;
#include "headers/Structure.h"
#include "headers/Array.h"
#include "headers/DoubleLinkedList.h"
#include "headers/Array2D.h"

int main() {
    /*std::cout << "Hello, World!" << std::endl;
    Array<int> arr;
    arr.create(10);
    //std::cout<<arr.extract(0)<<std::endl;
    arr.init();
    //std::cout<<arr.extract(0)<<std::endl;
    arr.insert(0,1);
    arr.insert(1,2);
    arr.insert(2,3);
    arr.insert(3,4);
    arr.insert(4,5);
    arr.insert(5,6);
    arr.insert(6,7);
    arr.insert(7,8);
    arr.insert(8,9);
    arr.insert(9,10);
    arr.show();
    arr.reverseMid();
    arr.show();
    arr.sort();
    arr.show();
    arr.sort("DES");
    arr.show();
    DoubleLinkedList<int> list;
    list.create();
    list.show();
    list.insert(0, 1);
    list.show();
    list.add(1);
    list.show();
    list.add(2);
    list.add(3);
    list.add(3);
    list.add(4);
    list.add(1);
    list.show();
    list.insert(5, 6);
    cout<<"CHECK INSERT"<<endl;
    list.show();
    list.remove(0);
    list.show();
    return 0;*/

    Array2D<int> matrix;
    Array2D<int> matrix2;
    Array2D<int> matrix3;
    matrix.create(4,4);
    matrix2.create(4,4);
    matrix3.create(4,4);
    matrix.show();
    matrix.insert(0, 1,2);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix.insert(i,j, (rand() % 10));
            matrix2.insert(i,j, (rand() % 3 + 1));
        }
    }
    matrix.insert(0,0 ,8);
    cout<<"M1"<<endl;
    matrix2.show();
    cout<<endl;
    cout<<"M2"<<endl;
    matrix.show();
    cout<<endl;
    matrix.multiplyTwo(matrix.array, matrix2.array, &matrix3.array);
    cout<<"M3"<<endl;
    matrix3.show();
    return 0;
}
