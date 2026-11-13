// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* speed = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(speed && speed->next) {
            prev = slow;
            slow = slow->next;
            speed = speed->next->next;
        }
        if (prev == nullptr) return nullptr;

        prev->next = slow->next;
        delete slow;
        return head;
    }
};
