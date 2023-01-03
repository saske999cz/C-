#include<iostream>
#include<math.h>

using namespace std;

bool CheckDX(int a[10][10], int n)
{   for(int i =0; i < n - 1;i++)
        for(int j = i+1; j < n; j++)
            if(a[i][j] != a[j][i])
             return false;
    return true;
}


long DT(int a[10][10], int n)
{
    for(int i = 0; i <= n; i++)
    {
        if(a[i][i] <= 0)
        {
            return -1;
        }
    }
    long ans1 = 1;
    long ans2 = 1;
    long ans;
    if(n == 0)
    {
        return a[0][0];
    }
    for(int i = 0; i <= n; i++)
    {
        ans1 *= a[i][i];
        ans2 *= a[i][n - i];
    }
    ans = ans1 - ans2;
    if(n == 2)
    {
        long k = pow(a[0][1] * a[1][2] * a[0][2], 2);
        long p = a[0][0] * a[0][1] * a[1][0] + a[1][2] * a[2][1] * a[2][2];
        ans = ans + k - p;
    }
    return ans;
}
bool CheckPos(int a[10][10], int n)
{
    for(int i =0; i < n; i++)
    {   if(DT(a, i) <= 0)
        return false;

    }
    return true;
}





int main()

{   int a[10][10];
    int n;
    cin >> n;
    
    cout << "Hay nhap ma tran " << n <<"x" << n <<" : "<< endl;
    for(int i =0;i< n;i++)
        for(int j=0; j<n;j++)
        cin>> a[i][j];

    cout << endl;
    if(CheckDX(a,n))
    cout << "Ma tran doi xung" << endl;
    else 
    cout << "Ma tran khong doi xung" << endl;

    if(CheckPos(a, n) == true)
        cout << "Ma tran xac dinh duong" << endl;
    else
        cout << "Ma tran khong xac dinh duong" << endl;




return 0;
}