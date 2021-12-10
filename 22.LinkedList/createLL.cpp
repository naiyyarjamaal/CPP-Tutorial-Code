

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

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data== key){
            return true;
        }
        temp= temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head= head->next;

    delete todelete;
}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data!=val){
        temp= temp->next;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

// iterative way to reverse  a linkelist...
node* reverseIterative(node* &head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

// recurrsive way to iterate a linkedlist...
node* reverseRecurrsive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead = reverseRecurrsive(head->next);
    head->next->next=head;
    head->next= NULL;

    return newHead;
}

// reverse k nodes of the linked list....
node* reversekNode(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next = reversekNode(nextptr, k);
    }
    
    return prevptr;
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

    cout<<search(head, 10)<<endl;

    deletion(head, 1);
    display(head);

    deleteAtHead(head);
    display(head);

    node* newHead = reverseIterative(head);
    display(newHead);

    node* newHead1 = reverseRecurrsive(newHead);
    display(newHead1);

    int k=2;
    node* reverseK = reversekNode(newHead1, k);
    display(reverseK);

    return 0;
}