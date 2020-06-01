#include<bits/stdc++.h>
using namespace std;

//Bottom Up

int main() {
	int n,amt;
	cin>>n>>amt;
	
	vector<int>coins(n);
	vector<vector<int>>dp(n+1,vector<int>(amt+1));
	
	for(int i=0;i<n;i++) {
		cin>>coins[i];
	}
	
	for(int i=0;i<=n;i++) {
		dp[i][0] = 1;
	}
	
	for(int j=1;j<=amt;j++) {
		dp[0][j] = 0;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=amt;j++) {
			if(coins[i-1] <= j) {
				int pick = dp[i][j-coins[i-1]];
				int drop = dp[i-1][j];
				
				dp[i][j] = pick+drop;
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

int changeways(vector<int>&coins,vector<vector<int>>&dp,int amt,int n) {
	
	if(amt == 0) {
		dp[n][amt] = 1;
		return 1;
	}
	
	if(n == 0 && amt != 0) {
		dp[n][amt] = 0;
		return 0;
	}
	
	if(dp[n][amt] != -1) {
		return dp[n][amt];
	}
	
	if(coins[n-1] <= amt) {
		int pick = changeways(coins,dp,amt-coins[n-1],n);
		int drop = changeways(coins,dp,amt,n-1);
		
		dp[n][amt] = pick+drop;		
		return dp[n][amt];
	}
	
	else {
		dp[n][amt] = changeways(coins,dp,amt,n-1);
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
	
	int answer = changeways(coins,dp,amt,n);
	cout<<answer<<endl;
	
	return 0;
}

*/
