#include<cstdio>
#include<string.h>
using namespace std;
const int maxn = 1000;
int a[maxn];
int t = 0;
char f;
int main(){
  char f;
  int temp;
  while(~scanf("%d",&temp)){
    memset(a,0,sizeof(a));
    a[0] = temp;
    t = 1;
    while((f = getchar()) && f != '\n'){
      // printf("%cn",f);
      scanf("%d",&temp);
      if(f == '+')a[t++] = temp;
      else if(f == '-') a[t++] = -temp;
      else if(f == '*') a[t] *= temp;
      else if(f == '/') a[t] /= temp;
    }
    int s = 0;
    // printf("%d\n", t);
    for(int i = 0 ; i < t ; i++) s += a[i];
    printf("%d\n", s);
  }
  return 0;
}
