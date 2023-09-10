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
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL)
        return nullptr;

        Node *original=head;
        Node *cloned=nullptr;
        Node *tmp=nullptr;

        while(original)
        {
            tmp=new Node(original->val);
            tmp->next=original->next;
            original->next=tmp;
            original=tmp->next;
        }   

        original=head;
        Node *newHead=head->next;

        while(original)
        {
            if(original->random)
            original->next->random=original->random->next;
            else
            original->next->random=nullptr;

            original=original->next->next;
        }

        original=head;

        while(original)
        {
            tmp=original->next;
            original->next=tmp->next;
            original=original->next;

            if(original)
            {
                tmp->next=original->next;
            }
            else
            tmp->next=nullptr;
        }
        return newHead;
    }
};