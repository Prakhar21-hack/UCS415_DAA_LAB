#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,W,H;
    cin >> N >> W >> H;

    int low=max(W,H), high=N*max(W,H);
    int ans=0;

    while(low<=high){
        int mid = (low+high)/2;

        int fit = (mid/W) * (mid/H);

        if(fit >= N){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    cout << ans;
}
