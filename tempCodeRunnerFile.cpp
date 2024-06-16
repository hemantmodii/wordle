#include<bits/stdc++.h>
using namespace std;

int checkfreq(vector<int> v)
{
    vector<int> alpha(26,0);

    for(int i = 0; i < v.size(); i++)
    {
        alpha[v[i] - 'a']++;
    }

    int maxi = alpha[0];
    int maxiindex = 0;

    for(int i = 1; i < 26; i++)
    {
        if(maxi < alpha[i])
        {
            maxi = alpha[i];
            maxiindex = i;
        }
    }
    cout<<"testing"<<endl;
    return maxiindex;
}

int differenceInConsecutive(int n, int k, string s) {
    vector<vector<int>> ans;
    for(int i = 0; i < n/k; i++)
    {
        for(int x = 0; x < k; x++)
        {
            ans[i][x] = s[i*k + x];
            cout<<"testing"<<endl;
        }
    }
    int count = 0;
    for(int i = 0 ; i < n/k; i++)
    {
        vector<int> sub = ans[i];
        int temp = checkfreq(sub);
        count += k - temp;
    }
    return count;

}
int main()
{
    string s = "abccdc";
    int ans = differenceInConsecutive(6,2,s);
    cout<<ans;
    return 0;
}