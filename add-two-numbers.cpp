//https://leetcode.com/problems/add-two-numbers
#include <iostream>
using namespace std;
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
        int sum = (l1->val + l2->val) % 10;
        int carry = l1->val + l2->val >= 10 ? 1 : 0;
        ListNode* result;
        result = new ListNode(sum);
        ListNode* tmp = result;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr) {
            sum = (l1->val + l2->val + carry) % 10;
            carry = l1->val + l2->val + carry >= 10 ? 1 : 0;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        } 
        while (l1 != nullptr) {
            sum = (l1->val + carry) % 10;
            carry = l1->val + carry >= 10 ? 1 : 0;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sum = (l2->val + carry) % 10;
            carry = l2->val + carry >= 10 ? 1 : 0;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l2 = l2->next;
        }
        if (carry != 0) {
            tmp->next = new ListNode(1);
        }
        return result;
    }
};

int main() {
    return 0;
}