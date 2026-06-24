/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(head!=slow){
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};