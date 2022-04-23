//
// Created by kira2 on 17/4/2022.
//

#ifndef PROJECT_STRUCTURE_H
#define PROJECT_STRUCTURE_H
template <typename T>
class Structure{
public:
    virtual void create(int size = INT32_MAX) = 0;
    virtual void insert(int pos, T data) = 0;
    virtual T extract(int pos) = 0;
    virtual void destroy() = 0;
    virtual void remove(int pos) = 0;
    virtual bool search(T data) = 0;
    virtual void show() = 0;
};
#endif //PROJECT_STRUCTURE_H
