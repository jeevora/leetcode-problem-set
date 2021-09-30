#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.


class BrowserHistory {

    struct ListNode {
        string val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(string x) : val(x), next(nullptr) {}
        ListNode(string x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* head = nullptr, *curr = head;
    int size = 0, currSize = 0;

    void pushBack(string data, ListNode*& head)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }     
        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }

public:

    BrowserHistory(string homepage) {
        pushBack(homepage,head);
        curr = head;
        size++;
        currSize = size;        
    }
    
    void visit(string url) {
        pushBack(url,head);
        curr = curr->next;
        size++;
        currSize = size;
    }
    
    string back(int steps) {

        ListNode* temp = head;
        int back = currSize - steps;

        while (--back && temp->next)
            temp = temp->next;

        curr = temp;
        currSize--;
        return temp->val;      
    }
    
    string forward(int steps) {

        ListNode* temp = curr;

        while (--steps && temp->next)
            temp = temp->next;
        
        curr = temp;
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){
    
    BrowserHistory* obj = new BrowserHistory("www.leetcode.com");
    obj->visit("www.googgle.com");
    obj->visit("www.facebook.com");
    obj->visit("www.youtube.com");

    string param_2 = obj->back(1);
    param_2 = obj->back(1);

    string param_3 = obj->forward(1);

    obj->visit("www.linkedin.com");

    param_3 = obj->forward(2);

    param_2 = obj->back(2);
    param_2 = obj->back(7);





}