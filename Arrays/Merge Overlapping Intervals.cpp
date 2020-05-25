/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

bool compare(Interval x,Interval y) {
    return(x.start < y.start);
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    
    if(A.size() == 0) {
        return A;
    }
    
    vector<Interval>answer;
    
    sort(A.begin(),A.end(),compare);
    
    answer.push_back(A[0]);
    
    for(int i=1;i<A.size();i++) {
        
        if(answer[answer.size()-1].end >= A[i].start) {
            answer[answer.size()-1].end = max(answer[answer.size()-1].end, A[i].end);
        }
        else {
            answer.push_back(A[i]);
        }
    }
    
    return answer;
}

