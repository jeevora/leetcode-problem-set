#include<iostream>

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};

class MyLinkedList {
public:
    
    int length;
    Node *head;
    /** Initialize your data structure here. */
    MyLinkedList() {        
        length = 0;
        head = NULL;        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < length && index >= 0){            
            Node *cur = head;
            for (;index > 0; index--)
                cur = cur->next;
            return cur->val;            
        }        
        else return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        
        if(head)
            head->prev = cur;

        cur->next = head;
        head = cur;
        length++;        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp = new Node(val);        
        length++;
        
        if(head){
            Node *cur = head;

            while (cur->next)
                cur = cur->next;
            
            cur->next = temp;
            temp->prev = cur;
        }
        else
            head = temp;        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if(index > length) return;

        if(index == 0){
            addAtHead(val);
        }
        else{         
            Node *cur = head;

            while(index-- > 0){
                cur = cur->next;
            }

            if(!cur){
                addAtTail(val);
                return;
            }

            Node *newnode = new Node(val);
            Node *temp = cur->next;
            
            cur->next = newnode;
            newnode->prev = cur;
            newnode->next = temp;
            temp->prev = newnode;
            length++;
        }        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if(index >= 0 && index < length){

            Node *temp = new Node(0);
            temp->next = head;

            Node *cur = temp;

            // delete at head
            if(index == 1){
                head = NULL;
                length--;
                return;
            }
                
            while(index > 0){
                cur = cur->next;
                index--;
            }

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->next = NULL;
            cur->prev = NULL;

            head = temp->next;
            length--;
        }
        else
            return;
    }
};

int main(){
    cin.sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    int val, index;
    cin >> val >> index;

    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    int param_1 = obj->get(1);
    obj->deleteAtIndex(1);
    param_1 = obj->get(1);
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */