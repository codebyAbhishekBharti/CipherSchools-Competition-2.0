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
        cout << head->data << ' ';
        head=head->next;
    }
    cout << endl;
}
int size(Node* head){
    int n=0;
    while(head){
        n++;
        head=head->next;
    }
    return n;
}

Node* reverse(Node* head,int k){
    const int len=size(head);
    if(!head or len<k) return head;

    Node* next=NULL;
    Node* prev=NULL;
    Node* current=head;
    for (int i = 0; i < k and current; i++)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    if(next) head->next=reverse(next,k);
    return prev;
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n;
    Node* head=make(n);
    cin >> k;
    head = reverse(head,k);
    print(head);
    return 0;
}