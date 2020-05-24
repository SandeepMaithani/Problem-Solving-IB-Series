/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    if(newInterval.start > newInterval.end) {
        int temp = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = newInterval.start;
    }
    
    if(intervals.size() == 0) {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    vector<Interval>answer;
    
    int x = 0;
    int y = x;
    
    for(int i=0;i<intervals.size();i++) {
        if(intervals[i].start <= newInterval.start) {
            answer.push_back(intervals[i]);
            x++;
            y++;
        }
        else {
            break;
        }
    }
    
    if(x == 0) {
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i].start <= newInterval.end) {
                newInterval.end = max(intervals[i].end,newInterval.end);
                y++;
            }
            else {
                break;
            }
        }
        answer.push_back(newInterval);
    }
    else if(intervals[x-1].end >= newInterval.start) {
        
        for(int i=x-1;i<intervals.size();i++) {
            if(intervals[i].start <= newInterval.end) {
                answer[x-1].end = max(intervals[i].end,newInterval.end);
                y++;
            }
            else {
                y--;
                break;
            }
        } 
    }
    else if(intervals[x-1].end < newInterval.start) {
        
        if(x == intervals.size()) {
            answer.push_back(newInterval);
        }
        else if(intervals[x].start > newInterval.end) {
            answer.push_back(newInterval);
        }
        else {
            for(int i=x;i<intervals.size();i++) {
                if(intervals[i].start <= newInterval.end) {
                    newInterval.end = max(intervals[i].end,newInterval.end);
                    y++;
                }
                else {
                    break;
                }
            }
            answer.push_back(newInterval);
        }
    }
    
    for(int i=y;i<intervals.size();i++) {
        if(newInterval.end < intervals[i].start) {
            answer.push_back(intervals[i]);
        }
    }
    
    return answer;
}

