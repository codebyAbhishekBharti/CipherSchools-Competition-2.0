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
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        Node* nn=new Node(data);
        tail->next=nn;
        tail=nn;
    }
    return head;
}
int max_twin(Node* head){
    vector<int>v;
    int max=0;
    while(head){
        v.push_back(head->data);
        head=head->next;
    }
    int left=0;
    int right=v.size()-1;
    while(left<right){
        int sum=v[left]+v[right];
        if(max<sum) max=sum;
        left++;
        right--;
    }
    return max;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Node* head=make(n);
    int res=max_twin(head);
    cout <<res;
    return 0;
}
