class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int num : s) {
            if (s.count(num + 1) == 0) {
                int localAns = 1;
                int counter = num;
                while (s.count(counter - 1) != 0) {
                    counter--;
                    localAns++;
                }
                ans = max(localAns, ans);
            }
        }
        return ans;
    }
};