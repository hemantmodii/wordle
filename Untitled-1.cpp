#include<bits/stdc++.h>
using namespace std;

int checkfreq(vector<char> &v)
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
    return maxiindex;
}

int differenceInConsecutive(int n, int k, string s) {
    vector<vector<char>> ans(n/k, {'a'});
    for(int i = 0; i < n/k; i++)
    {
        vector<char>temp;
        for(int x = 0; x < k; x++)
        {
            temp.push_back(s[i*k + x]);
        }
        ans[i] = temp;
    }
    int count = 0;
    for(int i = 0 ; i < n/k; i++)
    {
        vector<char> sub = ans[i];
        int temp = checkfreq(sub);
        count += k - temp;
    }
    return count;

}
int main()
{
    string s = "khkkdkuki";
    int ans = differenceInConsecutive(9,3,s);
    cout<<ans;
    return 0;
}