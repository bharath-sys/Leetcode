class MyCalendar {
public:
    // static bool comparator(pair<int,int> &A,pair<int,int> &B){
    //     return A.second > B.second;
    // }
    // priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>
    vector<pair<int, int>> pq;
    MyCalendar() {}

    bool book(int s, int e) {
        for (auto [x, y] : pq) {
            if (!(s < x && e <= x) && !(s >= y && e > y)) {
                return false;
            }
        }
        pq.push_back({s, e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */