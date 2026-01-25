#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};
void print(Node* &head) {
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
};
Node* mergeTwoLists(Node* list1, Node* list2) {
    if(list1==NULL){
      return list2;
    }
    if(list2==NULL){
      return list1;
    }
    Node* small;
    Node* big;
    if(list1->data < list2->data) {
        small = list1;
        big = list2;
    } else {
        small = list2;
        big = list1;
    }
    

    Node* temp = big;
    Node* cur = small;
    Node* next = small->next;
    Node* next2 =  big->next;
    if(next==NULL){
      cur->next = temp;
      return cur;
    }
    

    while(temp!=NULL and next!=NULL){
      if(temp->data >= cur->data and temp->data<=next->data){
         cur->next = temp;
         next2 = temp->next;
         temp->next = next;
         cur = temp;
         temp=next2;
      }
      else{
        cur=next;
        next=next->next;
        if(next==NULL){
          cur->next=temp;
          print(small);
          return small;
        }

      }
      
    }

    print(small);

    return small;  
}
void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}


int main() {
    
    //created a new node
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    
    //head pointed to node1
    Node* head1 = node1; 
    Node* tail1 = node1;

    Node* head2 = node2;
    Node* tail2 = node2;
    

    insertAtTail(tail1, 4);
    insertAtTail(tail1, 7);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 5);
    mergeTwoLists(head1,head2);




    return 0;
}