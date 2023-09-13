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

void right_rotate(Node* &head,int k){
    if(!head or !head->next or k==0) return;
    int size=0;
    Node* end=NULL;
    Node* temp=head;
    while (temp)
    {
        end=temp;
        size++;
        temp=temp->next;
    }
    k=k%size;
    if(k==0) return ;
    temp=head;
    Node* rotate_head=NULL;
    for(int i=1;i<size-k;i++){
        temp=temp->next;
    }
    rotate_head=temp->next;
    temp->next=NULL;
    end->next=head;
    head=rotate_head;
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n;
    Node* head=make(n);
    cin >> k;
    right_rotate(head,k);
    print(head);
    return 0;
}