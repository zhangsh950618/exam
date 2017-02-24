#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
  int a,b,tem_a;
  char c;
  scanf("%d\n", &a);
  printf("%d\n", a);
    while(c = getchar()){
      printf("%c\n", c);
      if(c == '\n')
        break;
      if(c == '*'){
        cin >> b;
        a = a * b;
      }else if(c == '/'){
        cin >> b;
        a = a / b;
      }else{
        cin >> b;
        while(tem_a = getchar()){
          if(tem_a == '*'){
            b = b * tem_a;
          }else if(tem_a == '/'){
            b = b /tem_a;
          }else{
            break;
          }
        }
        if(c == '+')
          a = a + b;
        else
          a = a - b;
        c = tem_a;
    }
    cout << "部分和为:" << a << endl;
  }
    cout << a << endl;
  return 0;
}
