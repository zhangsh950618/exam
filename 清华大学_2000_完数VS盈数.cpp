#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100;
int wan[maxn],ying[maxn];
int tot_wan,tot_ying;
bool is_prime[maxn];
int tot_prime,prime[maxn];
void Elur(){
  memset(is_prime,true,sizeof(is_prime));
  for(int i = 2 ; i < maxn ; i++){
    if(is_prime[i]) prime[tot_prime++] = i;
    for(int j = 0 ; j < tot_prime ; j++){
      if(i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if(i % prime[j] == 0) break;
    }
  }

}
int solve(int num){

  int sum  = 0;
  int temp = num;
  cout << "temp" << temp << endl;
  for(int i = 0 ; i < tot_prime ; i++){
    while(temp % prime[i] == 0 && prime[i] < num && temp){
      sum += prime[i];
      temp /= prime[i];
      cout << "prime:" << prime[i] << endl;
    }
  }
  if(sum > num) return 2;
  if(sum == num) return 1;
  return 0;

}
int main(){
  Elur();
  cout << "tot_prime" << tot_prime << endl;
  for(int i = 2 ; i <= 60 ; i++){
    int ans = solve(i);
    if(ans == 1) wan[tot_wan++] = i;
    else if(ans == 2) ying[tot_ying++] = i;
  }
  cout << "tot_wan" << tot_wan << endl;
  cout << "tot_ying" << tot_ying << endl;
  cout << "E: ";
  int i;
  for(i = 0 ; i < tot_wan - 1 ; i++)
  cout << wan[i] << " ";
  cout << wan[i] << endl;
  for(i = 0 ; i < tot_ying - 1 ; i++)
  cout << ying[i] << " ";
  cout << ying[i] << endl;

}
