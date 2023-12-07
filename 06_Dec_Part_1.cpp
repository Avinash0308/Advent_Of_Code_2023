#include<bits/stdc++.h>
using namespace std;
long long int find(long long int a, long long int b){
    long long int tot = 0;
    for(int i = 1; i<a; i++){
        if(i*(a-i) > b) tot++;
    }
    return tot;
}
int main(){
    long long int ans = 1;
    ans = find(63,411);
    ans *= find(78,1274);
    ans *= find(94,2047);
    ans *= find(68,1035);
    cout<<ans<<endl;
}