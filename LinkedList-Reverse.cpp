#include<iostream>
#include<map>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};

void printReverse(ListNode* head) {
    if(head == NULL) {
        return;
    }
    printReverse(head->next);  
    cout << head->data << " ";  
}
void insertAtHead(ListNode* &head, int d) {

    // new node create
    ListNode* temp = new ListNode(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(ListNode* &tail, int d) {
     // new node create
    ListNode* temp = new ListNode(d);
    tail -> next = temp;
    tail  = temp;
}
void insertAtPosition(ListNode* &tail, ListNode* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    ListNode* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    ListNode* nodeToInsert = new ListNode(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}



int main() {
    
    ListNode* node1 = new ListNode(10);
  
    ListNode* head = node1; 
    ListNode* tail = node1;
    insertAtPosition(tail,head, 2, 22);
    insertAtPosition(tail,head,3,21);
    printReverse(head);

   

    return 0;
}