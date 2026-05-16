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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* help = nullptr;
        if (list1->val <= list2->val) {
            head = list1;
            help = list2;
        } else {
            head = list2;
            help = list1;
        }

        ListNode* cur = head;

        while (cur->next != nullptr and help != nullptr) {
            if (cur->next->val <= help->val) {
                cur = cur->next;
            } else {
                ListNode* temp = cur->next;
                cur->next = help;
                cur = help;
                help = temp;
            }
        }

        if (help != nullptr) {
            cur->next = help;
        }

        return head;
    }
};
