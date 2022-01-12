#include <bits/stdc++.h>
using namespace std;

int rowMax(vector<vector<int>> a, int n, int m)
{
    int r = 0, c = m - 1,ans = -1;
    while (r < n && c >= 0 )
    {
        if (arr[r][c] == 1)
        {
            ans = r
            c--;
        }
        else
        {
            r++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> a;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Ans : " << rowMax(a, n, m);
    return 0;
}