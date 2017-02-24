#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<time.h>
#include<stack>
using namespace std;
#define N 1200000
#define INF 0x3f3f3f3f

int dp[N];
int a[N];

int main()
{
    int n,m,T,i,j;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &n, &m);
        memset(dp,0,sizeof(dp));

        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            dp[i]=dp[i-1]+a[i];
        }

        int minn=INF,i=1;;
        for(j=1;j<=n;j++)
        {
             if(dp[j]-dp[i-1]<m)
                continue ;
             while(dp[j]-dp[i]>=m)
                i++;
             minn=min(minn,j-i+1);
        }

      if(minn==INF)
        printf("0\n");
      else
        printf("%d\n", minn);
    }
    return 0;
}
