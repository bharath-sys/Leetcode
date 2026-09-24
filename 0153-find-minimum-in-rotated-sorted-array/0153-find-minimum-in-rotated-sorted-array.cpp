class Solution {
public:
    int findMin(vector<int>& arr) {
        int mini = INT_MAX;
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[l] <= arr[m]) {
                mini = min(arr[l], mini);
                l = m + 1;
            } else {
                mini = min(arr[m], mini);
                r = m - 1;
            }
        }
        return mini;
    }
};