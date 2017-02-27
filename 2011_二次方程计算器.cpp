#include<string.h>
#include<string>
#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
// ifstream cin("1.in");
// ofstream cout("1.out");
string st;
struct Node{
  int a;
  int b;
  int c;
};
bool is_number(char c){
  return c >= '0' && c <= '9';
}
Node solve(string st){
  int l = st.length();
  Node node = (Node){0, 0, 0};
  // printf("a = %d, b = %d, c = %d\n",node.a, node.b , node.c);
  int i = 0;
  int op = 1;
  int v = 0;
  while(i < l){
    if(is_number(st[i])){
      v = 0;
      while(is_number(st[i]))
      v = v * 10 + st[i++] - '0';
    }else if(st[i] == 'x'){
      if(v == 0) v = 1;
      if(i + 2 < l && st[i + 1] == '^' && st[i + 2] == '2'){ //二次方
        node.a += op * v;

        i += 3;
      }else{//一次方
        node.b += op * v;
        i++;
      }
      v = 0;
    }else{//'+'或者'-'
      char f = st[i];
      node.c += op * v;
      if(f == '+') op = 1;
      else op = -1;
      v = 0;
      i++;
    }
  }
  // printf("a = %d, b = %d, c = %d\n",node.a, node.b , node.c);
  return node;
}
int main(){
  while(cin >> st){
    // cout << st << endl;
    int pos = st.find('=');
    Node left = solve(st.substr(0, pos)+ "+");
    Node right = solve(st.substr(pos + 1) + "+");
    int a = left.a - right.a;
    int b = left.b - right.b;
    int c = left.c - right.c;
    int d = pow(b, 2) - 4 * a * c;
    if(d < 0){
      cout << "No Solution" << endl;
    }else{
      double a1 = (-b + sqrt(d)) / (2 * a);
      double a2 = (-b - sqrt(d)) / (2 * a);
      if(a1 > a2) swap(a1 , a2);
      printf("%.2lf %.2lf\n", a1, a2);
    }
  }
  return 0;
}
