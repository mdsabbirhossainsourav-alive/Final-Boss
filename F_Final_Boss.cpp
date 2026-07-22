#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) 
    {
        long long h;
        int n;
        cin >> h >> n;
        vector<long long> a;
        vector<long long> c;
        for(int i=0; i<n; i++) 
        {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        for(int i=0; i<n; i++) 
        {
            long long x;
            cin >> x;
            c.push_back(x);
        }
        long long lft = 1;
        long long rgt = h;
        while(rgt > 0) 
        {
            long long dmg = 0;
            for(int i=0; i<n; i++) 
            {
                long long tms = rgt / c[i];
                if(rgt % c[i] != 0)
                {
                    tms++;
                }
                dmg += tms * a[i];
            }
            if(dmg >= h)
            {
                break;
            }
            rgt *= 2;
        }
        while(lft < rgt) 
        {
            long long mid = (lft + rgt) / 2;
            long long dmg = 0;
            for(int i=0; i<n; i++) 
            {
                long long tms = mid / c[i];
                if(mid % c[i] != 0)
                {
                    tms++;
                }
                dmg += tms * a[i];
            }
            if(dmg >= h)
            {
                rgt = mid;
            }
            else
            {
                lft = mid + 1;
            }  
        }
        cout << lft << endl;
    }
    return 0;
}