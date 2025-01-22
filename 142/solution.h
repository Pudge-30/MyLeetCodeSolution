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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head->next;
        ListNode* fast = nullptr;
        if (slow != nullptr)
            fast = slow->next;
        while (slow != fast && slow != nullptr && fast !=nullptr)
        {
            slow = slow->next;
            if (fast->next != nullptr)
                fast = fast->next->next;
            else fast = nullptr;
        }

        if (slow == nullptr || fast == nullptr)
            return nullptr;
        
        ListNode* cycle_head = head;
        while (cycle_head != slow)
        {
            cycle_head = cycle_head->next;
            slow = slow->next;
        }
        return slow;
    }
};