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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* pre = nullptr;
        while (p != nullptr)
        {
            if (p->val == val)
            {
                if (pre != nullptr)
                {
                    pre->next = p->next;
                    delete p;
                    p  = pre->next;
                } else{
                    head = p->next;
                    delete p;
                    p = head;
                }
            } else{
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};