#pragma once

#include <string>
#include <cmath>
using std::string;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        ListNode* p0 = head;
        ListNode* pn = head;
        ListNode* pre = nullptr;
        for (int i =0; i < n-1; i++)
        {
            if (pn->next != nullptr)
                pn = pn->next;
            else
                return head;
        }
        while (pn->next != nullptr)
        {
            pn = pn->next;
            pre = p0;
            p0 = p0->next;
        }

        if (pre != nullptr)
        {
            pre->next = p0->next;
            delete p0;
            return head;
        } else{
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        return nullptr;

    }
};