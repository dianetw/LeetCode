/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 * Example 2:
 * Input: head = []
 * Output: []
 *
 * Example 3:
 * Input: head = [1]
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 */
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
/** 遞歸 **/
// T(N) = T(N - 2) + O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }

};

/** 迭代 **/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dum = new ListNode(-1);
        ListNode* prev = dum;
        dum->next = head;
        while (prev->next && prev->next->next) {
            ListNode* temp = prev->next->next;
            prev->next->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp->next;
        }
        return dum->next;
    }

};