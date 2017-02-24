#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
double xx0,yy0,zz0,xx1,yy1,zz1;
const double PI = acos(-1);
int main(){
  while(cin >> xx0 >> yy0 >> zz0 >> xx1 >> yy1 >> zz1){
    double r = sqrt(pow(xx1 - xx0,2) + pow(yy1 - yy0,2) + pow(zz1 - zz0,2));
    double v =  4 * PI * pow(r,3) / 3;
    printf("%.3f %.3f\n",r,v);
  }
  return 0;
}
