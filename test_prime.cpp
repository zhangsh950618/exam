#include<iostream>
#include<math.h>
using namespace std;
int is_prime(int num){
  int lim = sqrt(num);
  for(int i = 2 ; i <= lim ; i++)
  if(num % i == 0) return 0;
  return 1;
}
int num;
int main(){
  while(cin >> num){
    if(is_prime(num)) cout << "this is prime" << endl;
    else cout << "this is not prime" << endl;
  }
  return 0;
}
