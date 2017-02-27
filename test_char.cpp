#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
  string a = "123";
  const char * ca = a.c_str();
  strcat(ca, "456");
  printf("%s\n",ca);
  return 0;
}
