// Put even elements after odd elements in linkedlist
#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head = n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;

    }

    temp->next = n;
}


void evenAfterOdd(node* &head){     // this part of code is not working....

    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next!=NULL && even->next!=NULL){

        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    node* head = NULL;
    insertAtTail(head, 23);
    insertAtTail(head, 768);
    insertAtTail(head, 234);
    insertAtTail(head, 12);
    display(head);

    insertAtHead(head, 1);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    display(head);

    evenAfterOdd(head);
    display(head);


    return 0;
}