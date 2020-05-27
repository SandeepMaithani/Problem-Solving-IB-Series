/*

string str1 = "089";
string str2 = "986";

idea is to sort vector in descending order on condition whether (str1+str2) > (str2+str1)

in above eg :

089986 > 986089

*/



bool strnum(string a,string b) {
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
 
    string str = "";
    vector<string>nums;
    
    for(int i=0;i<A.size();i++) {
        nums.push_back(to_string(A[i]));
    }
    
    sort(nums.begin(),nums.end(),strnum);
    
    for(int i=0;i<nums.size();i++) {
        str += nums[i];
    }
    
    while(str[0] == '0' && str.length() != 1) {
        str.erase(str.begin());
    }
    
    return str;
    
}

