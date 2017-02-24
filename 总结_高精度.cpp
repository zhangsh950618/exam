#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100;
string a,b;
char flag;
int num_a[maxn],num_b[maxn],ans[2*maxn];
void sub(string a,string b){

  //全部进行初始化
  memset(num_a,0,sizeof(num_a));
  memset(num_b,0,sizeof(num_b));
  memset(ans,0,sizeof(ans));

  //交换a，b保证大的减去小的，避免负数问题
  if(a.length() < b.length() || a.length() == b.length() && a < b){
    string temp = a;
    a = b;
    b = temp;
    cout << "-";
  }

  int len_a = a.length();
  int len_b = b.length();
  for(int i = 0 ; i < len_a ; i++) num_a[i] = a[len_a - 1 - i] - '0';
  for(int i = 0 ; i < len_b ; i++) num_b[i] = b[len_b - 1 - i] - '0';

  for(int i = 0 ; i < len_a ; i++){
    if(num_a[i] < num_b[i]){
      num_a[i] += 10;
      num_a[i + 1] --;
    }
    ans[i] = num_a[i] - num_b[i];
  }
  //去除前置0
  int i = len_a - 1;
  while(ans[i] == 0 && i > 0) i--;
  for( ; i >= 0 ; i--) cout << ans[i];
  cout << endl;
}
void add(string a,string b){
  memset(num_a,0,sizeof(num_a));
  memset(num_b,0,sizeof(num_b));
  memset(ans,0,sizeof(ans));
  int len_a = a.length();
  int len_b = b.length();
  for(int i = 0 ; i < len_a ; i++) num_a[i] = a[len_a - 1 - i] - '0';
  for(int i = 0 ; i < len_b ; i++) num_b[i] = b[len_b - 1 - i] - '0';
  //进位标志
  int flag = 0;

  for(int i = 0 ; i < max(len_a,len_b) ; i++){
    int sum = num_a[i] + num_b[i] + flag;
    ans[i] = sum % 10;
    flag = sum / 10;
  }
  if(flag) cout << flag;
  for(int i = max(len_a,len_b) -1 ; i >= 0 ; i--) cout << ans[i];
  cout << endl;
}

void mul(string a,string b){


  memset(num_a,0,sizeof(num_a));
  memset(num_b,0,sizeof(num_b));
  memset(ans,0,sizeof(ans));
  int len_a = a.length();
  int len_b = b.length();
  for(int i = 0 ; i < len_a ; i++) num_a[i] = a[len_a - 1 - i] - '0';
  for(int i = 0 ; i < len_b ; i++) num_b[i] = b[len_b - 1 - i] - '0';
  //用于存储部分乘积
  int temp[maxn] = {0};
  int i,j;
  //开始计算，用b[i] * a = temp,然后再将temp和ans错开i位相加
  for(i = 0 ; i < len_b ; i++){
    memset(temp,0,sizeof(temp));
    //计算部分积的进位
    int flag_mul = 0;

    for(j = 0 ; j < len_a ; j++){
      int m = num_a[j] * num_b[i] + flag_mul;
      // cout << "num_a:"<< num_a[i] << " num_b:" << num_b[i] << " m = " << m << endl;
      flag_mul = m / 10;
      temp[j] = m % 10;
    }
    temp[j] = flag_mul;
    // if(flag_mul) cout << flag_mul;
    // for(j = len_a ; j >= 0 ; j--) cout << temp[j] << endl;
    int falg_add = 0;
    for(j = 0 ; j <= len_a ; j++){
      int m = ans[j +i] + temp[j] + falg_add;
      falg_add = m / 10;
      ans[i+j] = m % 10;
    }
    while(falg_add){
      int m = ans[i+j] + falg_add;
      falg_add = m / 10;
      ans[i + j] = m % 10;
      j++;
    }

  }
  // 去除前置0
  i = len_a + len_b + 1;
  while(ans[i] == 0 && i > 0) i--;
  for( ; i >= 0; i--) cout << ans[i];
  cout << endl;

}
int main(){
  //预处理
  while(cin >> a >> flag >> b){
    if(flag == '-') sub(a,b);
    if(flag == '+') add(a,b);
    if(flag == '*') mul(a,b);
  }
  return 0;
}
