/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool static compare(Interval lhs, Interval rhs) { 
        return lhs.start < rhs.start; 
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        std::sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size(); i++) {
            if(!pq.empty()) {
                if(pq.top() <= intervals[i].start) {
                    pq.pop();
                }
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
