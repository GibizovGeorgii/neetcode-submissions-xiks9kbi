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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* next_node = head->next;
        head->next = nullptr;
        ListNode* prev_node = head;
        while (next_node != nullptr) {
            ListNode* temp_node = next_node->next;
            next_node->next = prev_node;
            prev_node = next_node;
            next_node = temp_node;
        }

        return prev_node;
    }
};
