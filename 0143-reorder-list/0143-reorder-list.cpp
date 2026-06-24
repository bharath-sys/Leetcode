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
    void stitch(ListNode* l1,ListNode* l2){
        while(l1 && l2){
            auto next = l1->next;
            auto next2 = l2->next;
            l1->next = l2;
            l2->next = next;
            l1 = next;
            l2 = next2;
        }
    }
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        auto next = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode *slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = reverse(slow->next);
        slow->next = NULL;
        stitch(head,list2);
    }
};