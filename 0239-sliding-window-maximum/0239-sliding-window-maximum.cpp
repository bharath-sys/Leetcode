class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            // 1. remove out of index 
            if(dq.size() && i-dq.front()+1>k)dq.pop_front();
            // 2. remove all smaller elements maintain decreasing queue 
            while(dq.size() && nums[dq.back()]<nums[i])dq.pop_back();
            // 3. push current element
            dq.push_back(i);
            // 4. push to ans array 
            if(i-k+1>=0)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};