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

void rearrange(Node* head){
    if (!head || !head->next) return;

    Node* odd=head;
    Node* even= head->next;
    Node* even_temp=even;
    while(even and even->next){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=even_temp;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Node* head=make(n);
    rearrange(head);
    print(head);
    return 0;
}