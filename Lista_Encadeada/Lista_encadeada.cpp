#include <iostream>
#include <stdlib.h>
#include <cassert>


class ListNode{

public:

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){
    }
    ListNode(int val, ListNode *next) : val(val), next(next){
    }
    ListNode(int val, ListNode *next){
        this -> val = val;
        this -> next = next;
    }
};

ListNode *insertback(ListNode *head, int val){
    if(head == nullptr){
        return new ListNode;
    }else{
        if(head -> next == nullptr){
            head -> next = new ListNode;
            return head;
        }else{
            insertback(head -> next, val);
            return head;
        }
    }
}

ListNode *merge(ListNode *head1, ListNode *head2){

    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }
    if(head1 -> val < head2 -> val){
        head1 -> next = merge(head1 -> next, head2);
        return head1;
    }else{
        head2 -> next = merge(head1 -> next, head2);
        return head2;
    }

}

//pega o Nth numero a partir do fim da lista
int getNthfromLast(ListNode *head, int n){

    ListNode *fast = head;
    ListNode *slow = head;

    for(int i=1; i<=n-1; i++){
        fast = fast -> next;
    }

    while(fast -> next != nullptr){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow -> val;

}
