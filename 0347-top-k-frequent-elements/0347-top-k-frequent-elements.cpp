class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int x : nums)
            mp[x] += 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto& [val, freq] : mp) {
            if (pq.size() < k) {
                pq.push({freq, val});
            } else {
                if (pq.top().first < freq) {
                    pq.pop();
                    pq.push({freq, val});
                }
            }
        }
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};