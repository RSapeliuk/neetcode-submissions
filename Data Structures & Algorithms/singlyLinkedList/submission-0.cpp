class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}

    Node(int val, Node* next) : val(val), next(next) {}
};


class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = tail = new Node(-1);
    }

    int get(int index) {
        Node* curr = head->next;
        int i = 0;
        while(curr != nullptr){
            if(i == index)
            {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head->next;
        head->next = newHead;
        if(newHead->next == nullptr){
            tail = newHead;
        }

    }
    
    void insertTail(int val) {
       Node* newTail = new Node(val);
        tail->next = newTail;
        tail = newTail;
    }

    bool remove(int index) {
       Node* curr = head;
        int i = 0;
        while(i<index && curr != nullptr){
            i++;
            curr = curr->next;
        }

        if(curr != nullptr && curr->next != nullptr)
        {
            if(curr->next == tail)
            {
                tail = curr;
            }
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false; 
    }

    vector<int> getValues() {
        vector<int> values;
        Node* curr = head->next;
        while(curr != nullptr){
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};
