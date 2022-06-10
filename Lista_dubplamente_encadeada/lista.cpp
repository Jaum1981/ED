#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node * prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {};
    Node(int val, Node * prev, Node * next) : val(val), prev(prev), next(next) {};
};

Node * readList(int n){
    if(n == 0){
        return nullptr;
    }else{
        int x;
        cout << "Entre com o elemento da lista:";
        cin >> x;
        Node * ptr = new Node(x);  
        ptr->next =  readList(n-1); //chamada recursiva
        if(ptr->next != nullptr)
            ptr->next->prev = ptr;
        return ptr;
    }

}
