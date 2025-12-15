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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val <= list2->val) {
            return this->merge(list1, list2);
        } else {
            return this->merge(list2, list1);
        }
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* head = list1;
        ListNode* prev = list1;
        list1 = list1->next;
        while (list1 != nullptr && list2 != nullptr) {
            if (list2->val <= list1->val) {
                prev->next = list2;
                list2 = list2->next;
                prev->next->next = list1;
                prev = prev->next;
            } else {
                prev = list1;
                list1 = list1->next;
            }
        }
        if (list2 != nullptr) {
            prev->next = list2;
        }
        return head;
    }
};

int main() {
    // Construct list1: -10 -> -9 -> -6 -> -4 -> 1 -> 9 -> 9
    ListNode* list1 = new ListNode(-10);
    list1->next = new ListNode(-9);
    list1->next->next = new ListNode(-6);
    list1->next->next->next = new ListNode(-4);
    list1->next->next->next->next = new ListNode(1);
    list1->next->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next->next = new ListNode(9);

    // Construct list2: -5 -> -3 -> 0 -> 7 -> 8 -> 8
    ListNode* list2 = new ListNode(-5);
    list2->next = new ListNode(-3);
    list2->next->next = new ListNode(0);
    list2->next->next->next = new ListNode(7);
    list2->next->next->next->next = new ListNode(8);
    list2->next->next->next->next->next = new ListNode(8);

    // Call the solution
    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}