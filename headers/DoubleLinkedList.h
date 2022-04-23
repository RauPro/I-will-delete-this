//
// Created by kira2 on 21/4/2022.
//

#ifndef PROJECT_DOUBLELINKEDLIST_H
#define PROJECT_DOUBLELINKEDLIST_H
template <typename T>
struct Node{
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class DoubleLinkedList: public Structure<T>{
private:
    Node<T> *list;
    int size = 0;
    void* createNode(){
        return malloc(sizeof (Node<T>));
    }
public:
    void create(int size = false) override{
        list = NULL;
    }
    void add(T data){
        Node<T>* newNode = (Node<T>*) createNode();
        newNode->value = data;
        newNode->prev = NULL;
        if (list == NULL){
            newNode->next = NULL;
        }else{
            list->prev = newNode;
            newNode->next = list;
        }
        list = newNode;
        size++;
    }

    void insert(int pos, T data) override{
        if (pos >= size){
            cout<<"Out of range"<<endl;
            return;
        }
        if(pos == 0){
            add(data);
            return;
        }
        Node<T>* newNode = (Node<T>*) createNode();
        newNode->value = data;
        Node<T>* listCopy = list;
        for(int i = 0; i < pos-1; i++) listCopy = listCopy->next;
        newNode->prev = listCopy;
        newNode->next = listCopy->next;
        listCopy->next->prev = newNode;
        listCopy->next = newNode;
        //list = listCopy;
    }
    void remove(int pos) override{
        if (pos > size){
            cout<<"Out of range"<<endl;
            return;
        }
        Node<T>* copyList = list;
        for (int i = 0; i < pos-1; ++i) {
            copyList = copyList->next;
        }
        Node<T> *tempDelete;
        if (copyList->next->next != NULL && copyList->prev != NULL){
            tempDelete = copyList->next;
            copyList->next = copyList->next->next;
            copyList->next->prev = copyList;
        }
        else if (copyList->next->next == NULL && copyList->prev!=NULL){
            tempDelete = copyList->next;
            copyList->next = NULL;
        }else{
            cout<<copyList->value<<endl;
            tempDelete = copyList;
            list = copyList->next;
        }
        free(tempDelete);
    }
    void show() override{
        Node<T> *aux = list;
        while (aux != NULL){
            cout<<aux->value<<" ";
            aux = aux->next;
        }
        cout<<endl;
    }
    bool search(T value) override{
        Node<T>* aux = list;
        while (aux != NULL){
            if (aux->value == value){
                return true;
            }
            aux = aux->next;
        }
        return false;
    }
    T extract(int pos) override {
        Node<T>* listCopy = list;
        for(int i = 0; i < pos; i++) listCopy = listCopy->next;
        return listCopy->value;
    }
    void destroy() override {
        Node<T>* temp;
        while(list != NULL){
            temp = list;
            list = list->next;
            free(temp);
        }
    }
};
#endif //PROJECT_DOUBLELINKEDLIST_H
