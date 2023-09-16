#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data):data(data),next(NULL){};
};
Node* make(int n){
    if(n==0) return NULL;
    int data;
    cin >> data;
    Node* head=new Node(data);
    Node* tail=head;
    for(int i=1;i<n;i++)
    {
        cin >> data;
        Node* nn=new Node(data);
        tail->next=nn;
        tail=nn;
    }
    return head;
}
void print(Node* head){
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}
class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
Node* merge(vector<Node*>lists) {
    priority_queue<Node*, vector<Node*>, Compare> min_heap;
    for (auto list : lists) {
        if (list) {
            min_heap.push(list);
        }
    }
    
    Node* head = new Node(-1);
    Node* tail = head;
    
    while (!min_heap.empty()) {
        Node* node = min_heap.top();
        min_heap.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) {
            min_heap.push(node->next);
        }
    }
    return head->next;
}


int main() {
    int n;
    cin >> n;
    vector<Node*> lists;
    int m;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        Node* head=make(m);
        lists.push_back(head);
    }
    Node* head = merge(lists);
    print(head);
    
    return 0;
}
