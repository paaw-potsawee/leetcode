// https://leetcode.com/problems/reverse-linked-list/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode* next = head->next;
        ListNode* prev = nullptr;
        while (head->next) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head->next = prev;
        return head;
    }
};
