#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head;
        int count = 0;
        int control = 1;
        for( int i = 0 ; iter != nullptr ; i++ ) {
            count++;
            iter = iter -> next;
        }
        if ( n == count ){
            control = 0;
        }
        if ( count == 1 ) {
            head = nullptr;
        }
        else if ( count == 2) {
            if (control) head -> next = nullptr;
            else return ( head -> next);
        }
        else {
            iter = head;
            if (!control) return ( head -> next);
            else{
                for ( int i = 0 ; i < ( count - n - 1) ; i++){
                    iter = iter -> next;
                }
            }
            ListNode* temp = iter->next;
            iter -> next = iter -> next -> next; 
            delete temp; 
        }
        iter = nullptr;
        return head;
    }
};

int main ( void ) {
    Solution sol;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    // ListNode *node1 = new ListNode(1);
    // node1->next = nullptr;

    // ListNode *node1 = new ListNode(1);
    // ListNode *node2 = new ListNode(2);
    // node1 ->next = node2;
    // node2->next = nullptr;

    ListNode* head = node1;
    head = sol.removeNthFromEnd(head, 2);
    ListNode* iter = head;
    for ( int i = 0 ; iter != nullptr ; i++){
        std::cout << iter -> val << " ";
        iter = iter -> next;
    }
    iter = head;
    while (iter != nullptr) {
        ListNode* temp = iter;
        iter = iter->next;
        delete temp; 
    }
    head = nullptr;
}