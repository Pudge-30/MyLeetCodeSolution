#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retvalue = new ListNode();
        retvalue->val = 0;
        retvalue->next = nullptr;
        if (l1 != nullptr && l2 ==nullptr)
        {
            retvalue->val = l1->val + carrybit;
        } else if (l2 != nullptr && l1 == nullptr)
        {
            retvalue->val = l2->val + carrybit;
        } else
        {
            retvalue->val = l1->val + l2->val + carrybit;
        }
        
        if (retvalue->val > 9)
        {
            retvalue->val = retvalue->val - 10;
            carrybit = 1;   
        } else
        {
            carrybit = 0;
        }

        ListNode* l1next = (l1 == nullptr) ? nullptr : l1->next;
        ListNode* l2next = (l2 == nullptr) ? nullptr : l2->next; 

        if (l1next != nullptr || l2next != nullptr)
        {
            retvalue->next = addTwoNumbers(l1next,l2next);
            carrybit = 0;
        } else if (carrybit == 1)
        {
            ListNode* thelast = new ListNode();
            thelast->val = 1;
            thelast->next = nullptr;
            retvalue->next = thelast;
            carrybit = 0;
        }
        return retvalue;
    }

    static int carrybit;

};
int Solution::carrybit = 0;
