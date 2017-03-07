#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct trie{
    int c;
    struct trie* next[26];
};

trie* create_node(){
    trie* node = new(trie);
    node->c = 0;
    memset(node->next, 0, sizeof(node->next));
    return node;
}

void trie_insert(trie* root, char* word){
        trie* node = root;
        char* p = word;
        while(*p){
            int id = *p - 'a';
            if(node->next[id] == NULL)
            node->next[id] = create_node();
            node = node->next[id];
            node->c++;
            p++;
        }
}


int trie_search(trie* root , char * word){
        trie* node = root;
        char*p = word;
        while(*p){
            int id = *p - 'a';
            node = node->next[id];
            if(node == NULL) return 0;
            p++;
        }
        return node->c;

}
const int size = 1000;
char st[size];
int main(){
    trie* root = create_node();
    int m, n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", st);
        trie_insert(root, st);
    }
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        scanf("%s", st);
        int c = trie_search(root, st);
        printf("%d\n", c);
    }





    return 0;
}
