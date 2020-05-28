bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>>record;
    int count = 0;
    
    for(int i=0;i<arrive.size();i++) {
        record.push_back(make_pair(arrive[i],1));
        record.push_back(make_pair(depart[i],-1));
    }
    
    sort(record.begin(),record.end());
    
    for(int i=0;i<record.size();i++) {
        count = count + record[i].second;
        
        if(count > K) {
            return false;
        }
    }
    
    return true;
}




