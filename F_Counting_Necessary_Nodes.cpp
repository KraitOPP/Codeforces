#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

inline int getNextNum(int x, int y, bool below) {
    if (below) return x - x % y;
    else return (x % y == 0 ? x : x + y - (x % y));
}

int solve(int l, int r, int s, int e, int sz) {
    if(l >= r || s >= e) return 0;
    if(r - l == 1) return e - s;
    if(e - s == 1) return r - l;
    
    for (int i = sz; i >= 0; i--) {
        int num = 1LL << i;
        int above = getNextNum(l, num, false);
        int low   = getNextNum(r, num, true);     
        int left  = getNextNum(s, num, false);    
        int right = getNextNum(e, num, true);      

        if(above < l || above >= r || low < l || low > r) continue;
        if(left < s || left >= e || right < s || right > e) continue;
        
        if(above >= low || left >= right) continue;
        
        int cnt1 = (low - above) / num;
        int cnt2 = (right - left) / num;
        if(cnt1 == 0 || cnt2 == 0) continue;
        
        int res = cnt1 * cnt2;
        int a = above, b = low, c = left, d = right;
        res += solve(l, a, s, c, i);  
        res += solve(l, a, c, d, i);  
        res += solve(l, a, d, e, i);   
        res += solve(a, b, s, c, i);   
        res += solve(a, b, d, e, i);  
        res += solve(b, r, s, c, i);   
        res += solve(b, r, c, d, i);   
        res += solve(b, r, d, e, i);   
        
        return res;
    }
    return 0;
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << solve(l1, r1, l2, r2, 20) << "\n";
    }
    return 0;
}
