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
        if (!head) return nullptr;

        Node* temp = head;

        while (temp) {
            Node* CopyNode = new Node(temp->val);
            CopyNode->next = temp->next;
            temp->next = CopyNode;
            temp = CopyNode->next;
        }

        temp = head;

        while (temp) {
            Node* CopyNode = temp->next;
            if (temp->random) {
                CopyNode->random = temp->random->next;
            } else {
                CopyNode->random = nullptr;
            }
            temp = CopyNode->next;
        }

        Node* dummynode = new Node(-1);
        Node* res = dummynode;
        temp = head;
        while (temp) {
            res->next = temp->next;
            res = res->next;
            
            temp->next = res->next; 
             
            temp = temp->next; 
            
        }

        return dummynode->next;
    }
};