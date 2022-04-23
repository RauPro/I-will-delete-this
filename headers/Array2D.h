//
// Created by kira2 on 22/4/2022.
//

#ifndef PROJECT_ARRAY2D_H
#define PROJECT_ARRAY2D_H
template <typename T>
class Array2D{
public:
    T** array;
    int n;int m;
    void create(int n, int m){
        this->n = n;
        this->m = m;
        array = (T**) malloc(sizeof (T*) * n);
        for (int i = 0; i < n; ++i) {
            *(array + i) = (T*) malloc(sizeof (T) * m);
        }
    }
    void insert(int row, int col, T data){
        *(*(array+row)+col) = data;
    }
    void show(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout<<array[i][j]<<" ";
            }cout<<endl;
        }
    }
    // 13
    void multiplyTwo(T** ma, T**mb, T*** mc){
        T** matrix3 = *mc;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix3[i][j] = ma[i][j]*mb[i][j];
            }
        }
    }
};
#endif //PROJECT_ARRAY2D_H
