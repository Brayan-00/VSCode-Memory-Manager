#include "iostream"
#include "../Dynamic_Library/garbageElement.h"
#include "../Dynamic_Library/VSPtr.h"


template<class T>
struct node {
    node() {}

    node* next;
    garbageElement<T> data;
};

template<class T>
class LinkedList
{
public:
    node<T> *head;
    node<T> *tail;
    LinkedList<T>() {
        head = NULL;
        tail = NULL;
    }

    void add(garbageElement<T> data) {
        if(!head) {
            // The list is empty
            head = new node<T>;
            head->data = data;
            head->next = NULL;
            tail = head;
        } else {
            // The list isn't empty
            if(tail == head) {
                // The list has one element
                tail = new node<T>;
                tail->data = data;
                tail->next = NULL;
                head->next = tail;
            } else {
                // The list has more than one element
                node<T> *insdata = new node<T>;
                insdata->data = data;
                insdata->next = NULL;
                tail->next = insdata;
                tail = insdata;
            }
        }
    }

    int length();

    T get(int index) {
        if(index == 0) {
            // Get the head element
            return this->head->data;
        } else {
            // Get the index'th element
            node<T> *curr = this->head;
            for(int i = 0; i < index; ++i) {
                curr = curr->next;
            }
            return curr->data;
        }
    }

    T operator[](int index) {
        return get(index);
    }

};