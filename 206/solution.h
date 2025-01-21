#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = nullptr;
        if (head != nullptr)
        {
            p = head->next;
            head->next = nullptr;
        }
        ListNode* p_next = nullptr;
        if (p != nullptr && p->next != nullptr)
            p_next = p->next;
        
        while (p != nullptr)
        {
            p->next = head;
            head = p;
            p = p_next;
            if (p != nullptr)
                p_next = p->next;
        }

        return head;
    }
};