/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head; 
        unordered_map<Node*, Node*> mp;

        while(curr != NULL){
            Node* clone = new Node(curr->val);
            mp[curr] = clone; //assigning value to it 
            curr = curr -> next;
        }

        //reset curr to head
        curr = head;
        while(curr != NULL){
            Node* clone = mp[curr];
            clone -> next = mp[curr->next];
            clone -> random = mp[curr->random];
            curr = curr-> next;
        }
        return mp[head];
    }
};
