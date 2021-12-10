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

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* mergeIterative(node* &head1, node* head2){

    node* p1=head1;     //ptr
    node* p2=head2;     //ptr
    node* dummyNode = new node(-1);     // it is a node but not a pointer...
    node* p3=dummyNode;     //ptr

    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}

node* mergeRecurrsive(node* &head1, node* &head2){      //this  function code is not working , do look again...

    if(head1==NULL){
        return head2;
    } 

    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data < head2->data){
        result=head1;
        result->next=mergeRecurrsive(head1->next, head2);
    }
    else{
        result=head2;
        result->next=mergeRecurrsive(head1, head2->next);
    }

    return result;
}

int main(){

    node* head1=NULL;
    node* head2=NULL;
    int a1[] = {1,3,4,6,8,9,12};
    int a2[] = {4,6,7,10,23,45};
    for(int i=0; i<7;i++){
        insertAtTail(head1, a1[i]);
    }

    for(int i=0; i<6;i++){
        insertAtTail(head2, a2[i]);
    }

    display(head1);
    display(head2);

    // node* newhead= mergeIterative(head2, head1);
    node* newhead = mergeRecurrsive(head1, head2);
    display(newhead);
    


    return 0;
}