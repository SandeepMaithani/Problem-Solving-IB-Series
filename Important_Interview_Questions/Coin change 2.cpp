#include<bits/stdc++.h>
using namespace std;

//Bottom Up

int main() {
	int n,amt;
	cin>>n>>amt;
	
	vector<int>coins(n);
	vector<vector<int>>dp(n+1,vector<int>(amt+1,0));
	
	for(int i=0;i<n;i++) {
		cin>>coins[i];
	}
	
	for(int j=1;j<=amt;j++) {
		dp[0][j] = INT_MAX-1;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=amt;j++) {
			
			if(coins[i-1] <= j) {
			    int pick = 1 + dp[i][j-coins[i-1]];
			    int drop = dp[i-1][j];
		
		        dp[i][j] = min(pick,drop);
			}
			else {
			    dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	int answer = dp[n][amt];
	cout<<answer<<endl;
	
	return 0;
}

//Recursion + Memoization

/*
int mincoins(vector<int>&coins,vector<vector<int>>&dp,int amt,int n) {
	
	if(amt == 0) {
        dp[n][amt] = 0;
		return 0;
	}
	
	if(amt != 0 && n == 0) {
        dp[n][amt] = INT_MAX-1;
		return INT_MAX-1;
	}
        
    if(dp[n][amt] != -1) {
        return dp[n][amt];
    }
	
	
	if(coins[n-1] <= amt) {
		int pick = 1 + mincoins(coins,dp,amt-coins[n-1],n);
		int drop = mincoins(coins,dp,amt,n-1);
		
		dp[n][amt] = min(pick,drop);
        return dp[n][amt];
	}
	else {
		dp[n][amt] = mincoins(coins,dp,amt,n-1);
        return dp[n][amt];
	}
}


int main() {
	int n,amt;
	cin>>n>>amt;
	
	vector<int>coins(n);
	vector<vector<int>>dp(n+1,vector<int>(amt+1,-1));
	
	for(int i=0;i<n;i++) {
		cin>>coins[i];
	}
	
	int answer = mincoins(coins,dp,amt,n);
	cout<<answer<<endl;
	
	return 0;
}
*/
