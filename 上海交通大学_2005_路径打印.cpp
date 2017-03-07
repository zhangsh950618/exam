#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int size = 100;
struct trie{
    string c;
    //左孩子，右兄弟存储
    struct trie* lc, rs;
};
int n;
char st[size];
trie* create_trie(){
    trie* node = new trie;
    node->c = "";
    node->lc = NULL;
    node->rs = NULL;
}
void insert_trie(trie* root ,char* word){

}
void print_trie(trie* root){
    if(root != NULL){



    }
}
int main(){
    //建立树根
    while(scanf("%d", &n) && n){
        trie* root = create_trie();
        for(int i = 0 ; i < n ; i++){
        scanf("%s", st);
        insert_trie(root, st);
        }
        print_trie(root);
    }
    return 0;
}

