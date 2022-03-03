#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
    Node *tail;
};

void CreateList(LinkedList &l){
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(int value){
    Node *node = new Node;
    node->data = value;
    node->next = NULL;
    return node;
}

void AddTail(LinkedList &l, Node *node){
    if(l.head == NULL){
        l.head = node;
        l.tail = node;
    }else {
        l.tail->next = node;
        l.tail = node;
    }
}

Node *SearchNode(LinkedList &l, int index){
    Node *node = l.head;
    int i=0;
    while(node != NULL && i != index ){
        node = node->next;
        i++;
    }
    if(node != NULL && i == index){
        return node;
    }
    return NULL;
}

void PrintList(LinkedList &l){
    Node *node = l.head;
    while(node != NULL){
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}
int main(){
    LinkedList list;
    CreateList(list);

    int n;
    int data;
    cout << "Enter the number of list" ;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Value of node " << i << " = ";
        cin >> data;
        AddTail(list, CreateNode(data));
    }

    PrintList(list);

    Node *temp = SearchNode(list, 3);
    cout << "Value of Node 3 " << temp->data << endl;

    return 0;
}

