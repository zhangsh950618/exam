#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
    char c;
    struct node* next;
};
node* create_node(){
    node* n = new node;
    n->c = 'a';
    n->next = NULL;
}
void insert_node(node* root, char c){
    node* n = root;
    while(n->next != NULL){
        n = n->next;
    }
    node* l = create_node();
    l->c = c;
    n->next = l;
}
void print_node(node* root){
    node* n = root;
    while(n){
        cout << n->c << endl;
        n = n->next;
    }
}
int main(){
    node* root = create_node();
    cout << "has create root node!" << endl;
    insert_node(root, 'c');
    insert_node(root, 'b');
    insert_node(root, 'd');
    insert_node(root, 'd');
    insert_node(root, 'e');
    insert_node(root, '');
    print_node(root);




    return 0;
}
