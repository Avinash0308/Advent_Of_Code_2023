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
    long long int ans = find(63789468,411127420471035);
    cout<<ans<<endl;
}