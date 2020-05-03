//
// Created by brayanrv on 2/5/20.
//
#include "../Dynamic_Library/library.h"
#include "iostream"
struct Node{
    struct Node *next;
    VSPtr<T> data;
    int id;
};
class SimpleList{
    //More methods remain to be implemented depending on project necessities
    private:
        Node *head;
        Node *tail;
        int length;
    public:
        SimpleList(){
            head = NULL;
            tail = NULL;
        }
        int next_id(){
            return length++;
        }
        void addNode(VSPtr<T> ptr){
            Node added;
            added.data = ptr;
            added.id = next_id();
            added.next = NULL;
            if(head == NULL){
                head = added;
                tail = added;
            }
            else{
                tail->next = added;
                tail = tail->next;
            }
        }
};