#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using std::string;
using std::vector;


class MyLinkedList {
public:

    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int val) :val(val), next(nullptr) {};
    };

    LinkNode* head = nullptr;
    int size = 0;

    MyLinkedList() {
        this->head = new LinkNode(0);
        this->size = 0;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        LinkNode* p = head;
        for (int i = 0; i <= index; i++)
        {
            if (p != nullptr)
            {
                p = p->next;
            }
            else return -1;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        LinkNode* new_p = new LinkNode(val);
        new_p->next = head->next;
        head->next = new_p;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode* tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        LinkNode* new_p = new LinkNode(val);
        tail->next = new_p;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        LinkNode* p = head;
        for (int i = 0; i < index; i++)
        {
            if (p != nullptr)
            {
                p = p->next;
            }
            else return;
        }
        LinkNode* new_p = new LinkNode(val);
        new_p->next = p->next;
        p->next = new_p;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        LinkNode* p = head;
        for (int i = 0; i < index; i++)
        {
            if (p != nullptr)
            {
                p = p->next;
            }
            else return;
        }
        LinkNode* del_p = p->next;
        p->next = del_p->next;
        delete del_p;
        size--;
    }

    void printval()
    {
        std::cout << "SIZE: " << size << std::endl;
        LinkNode* p = head->next;
        while (p!=nullptr)
        {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */