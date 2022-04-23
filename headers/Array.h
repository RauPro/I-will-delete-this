//
// Created by kira2 on 17/4/2022.
//

#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

template<typename T>
class Array: public Structure<T>{
private:
    T *array;
    int size;
public:
    void create(int dim) override{
        this->size = dim;
        array =(T*) malloc(sizeof (T)*size);
    }
    void init(){
        for (int i = 0; i < size; ++i) {
            array[i] = (T) 0;
        }
    }
    void remove(int pos) override{
        if (pos >= size){
            cout<<"Out of range"<<endl;
            return;
        }
        array[pos] = 0;
    }
    void insert(int pos, T data) override{
        array[pos] = data;
    }
    T extract(int pos) override{
        return array[pos];
    }
    void destroy() override{
        free(array);
    }
    bool search(T data) override{
        for (int i = 0; i < size; ++i) {
            if (array[i]==data)return true;
        }
        return false;
    }
    void show() override{
        for (int i = 0; i < size; ++i) {
            std::cout<<array[i]<<" ";
        }std::cout<<std::endl;
    }
    //23 - Similar idea for 24-27 and 25-26(Use n as mid)
    void reverseMid() {
        int mid = (size-1) / 2;
        for (int i = 0; i < (mid/2); ++i) {
            int aux = array[mid - i];
            array[mid - i] = array[i];
            array[i] = aux;
        }
    }
    // 22
    void sort(string type = "ASC"){
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (array[i] > array[j] && type == "ASC"){
                    int aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
                }
                if (array[i] < array[j] && type == "DES"){
                    int aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
                }
            }
        }
    }
};


#endif //PROJECT_ARRAY_H
