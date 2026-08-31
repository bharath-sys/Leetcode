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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        ListNode* prev = head;
        ListNode* temp = head->next;
        int idx = 1;
        vector<int> criticalList;
        for (; temp->next != nullptr; temp = temp->next, idx++) {
            bool localMax = temp->val > prev->val && temp->val > temp->next->val;
            bool localMin = temp->val < prev->val && temp->val < temp->next->val;
            prev = temp;
            if(localMax || localMin){
                criticalList.push_back(idx);
            }
        }
        if(criticalList.size()<2)return {-1,-1};
        int lastIdx = criticalList[0];
        for(int i=1;i<criticalList.size();i++){
            minDist = min(minDist,criticalList[i]-lastIdx);
            lastIdx = criticalList[i];
        }
        maxDist = criticalList.back() - criticalList.front();
        return {minDist, maxDist};
    }
};