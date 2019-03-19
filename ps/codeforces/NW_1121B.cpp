#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("1121b_input.txt");
    int N, result, array[1000], dp[200001] = {0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            dp[array[i]+array[j]]++;
        }
    }
    for (int i = 0; i < 200001; i++) {
        result = max(result, dp[i]);
    }
    cout << result;
    
    return 0;
}

//original: raghad_katbi2000
// #include<bits/stdc++.h>
// using namespace std;
// int a[1001],n,i,j,dp[200001],mx;
// int main(){
// 	cin>>n;
// 	for(i=0;i<n;i++)cin>>a[i];
// 	for(i=0;i<n;i++)
// 	for(j=i+1;j<n;j++)
// 	dp[a[i]+a[j]]++;
// 	for(i=0;i<200001;i++)mx=max(mx,dp[i]);
// 	cout<<mx;
// }
