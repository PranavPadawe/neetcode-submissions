/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start,end;
        for(auto it: intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int ans = 0;
        int rooms = 0;
        int l = 0 , r = 0;
        while(l < intervals.size()){
            if(start[l]<end[r]){
                l++;
                rooms++;
                ans = max(rooms,ans);
            }
            else{
                rooms--;
                r++;
            }
        }
        return ans;
    }
};
