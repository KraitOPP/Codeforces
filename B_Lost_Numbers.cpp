#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        vector<int> res = {4,8,15,16,23,42};

        vector<int> qry;
        for(int i=1;i<=4;i++){
            cout<<"? "<<i<<" "<<i+1<<endl;
            cout.flush();
            int tmp;
            cin>>tmp;
            qry.push_back(tmp);
        }

        do{
            bool flag=true;
            for(int i=0;i<4;i++){
                if((res[i]*res[i+1])!=qry[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) break;
        } while(next_permutation(res.begin(),res.end()));

        cout<<"! ";
        for(int i=0;i<6;i++) cout<<res[i]<<" ";
        cout<<endl;
        cout.flush();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}