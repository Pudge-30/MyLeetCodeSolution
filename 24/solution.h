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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p0 = head;
        ListNode* p1 = nullptr;
        ListNode* pre = nullptr;
        if (p0 != nullptr) p1 = p0->next;
        if (p0 != nullptr && p1 == nullptr) return head;
        ListNode * new_head = p1;

        while (p0 != nullptr && p1 != nullptr)
        {
            p0->next = p1->next;
            p1->next = p0;

            if (pre != nullptr)
            {
                pre->next = p1;
            }
            pre = p0;

            p0 = p0->next;
            if (p0 != nullptr)
            {
                p1 = p0->next;
            } else p1 = nullptr;
        }
        return new_head;
    }
};