#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
string a,b;
int num_a[maxn],num_b[maxn];
int add_res[maxn],sub_res[maxn],mul_res[maxn * 2],tem_res[maxn * 2];
int len_a,len_b;
void add(){
  int flag = 0;
  int len = max(len_a,len_b);
  for(int i = 0 ; i <= len ; i++){
    int sum = num_a[i] + num_b[i] + flag;
    add_res[i] = sum % 10;
    flag = sum / 10;
  }
  if(add_res[len])
  cout << add_res[len];
  for(int i = len - 1 ; i >= 0 ;i--){
    cout << add_res[i];
  }
  cout << endl;
}
int cmp(){
  int len = max(num_a,num_b);
  for()
}
void sub(){
  int flag = 0;
  int len = max(len_a,len_b);
  for(int i = 0 ; i < len ; i++){
      int sum = num_a[i] - num_b[i] - flag;
      if(sum < 0 && i + 1 < len_a){
        sum += 10;
        flag = 1;
      }else{
        flag = 0;
      }
      sub_res[i] = sum;
  }
  int i;
  for(i = len ; i >= 0 ; i--){
    if(sub_res[i])break;
  }
  for(;i >= 0; i--)
  cout <<sub_res[i];
  cout << endl;
}
void mul(){

  int len = 0;
  for(int i = 0 ; i < len_b ; i++){
    int b = num_b[i];
    int flag = 0;
    memset(tem_res,0,sizeof(tem_res));
    for(int j = 0 ; j <= len_a ; j++){
      int sum = b * num_a[j] + flag;
      tem_res[j] = sum % 10;
      flag = sum / 10;
    }
    flag = 0;
    for(int j = 0 ; j <= len ; j++){
      int sum = mul_res[i+j] + tem_res[j] + flag;
      mul_res[i+j] = sum % 10;
      flag = sum / 10;
    }
  }
  int i;
  for(i = len_a + len_b ; ; i--){
    if(mul_res[i] != 0){
      break;
    }
  }
  for( ; i >= 0 ; i--)
  cout << mul_res[i];
  cout << endl;
}
int main(){
  while(cin >> a >> b){
    memset(num_a,0,sizeof(num_a));
    memset(num_b,0,sizeof(num_b));
    memset(add_res,0,sizeof(add_res));
    memset(sub_res,0,sizeof(sub_res));
    memset(mul_res,0,sizeof(mul_res));
    len_a = a.length();
    len_b = b.length();
    for(int i = 0 ; i < len_a ; i++) num_a[i] = a[len_a - 1 - i] - '0';
    for(int i = 0 ; i < len_b ; i++) num_b[i] = b[len_b - 1 - i] - '0';
    // add();
    sub();
    // mul();
  }
  return 0;
}
