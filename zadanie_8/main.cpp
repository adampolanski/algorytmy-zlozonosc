#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

const int _INT_MAX = 2147483647;

struct Node {
    vector<Node*> edges;
    Node* pair;
    int distance = INT_MAX;
    
    Node(){}
};

struct Queue {
    struct QueueEntity {
        void* data;
        QueueEntity* next;
        QueueEntity* prev;

        QueueEntity(void* data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    
    QueueEntity* head;
    QueueEntity* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(void* data) {
        if(head == nullptr) {
            head = new QueueEntity(data);
            tail = head;
        } else {
            QueueEntity* newHead = new QueueEntity(data);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
    }

    void push_back(void* data) {
        if(tail == nullptr) {
            tail = new QueueEntity(data);
            head = tail;
        } else {
            QueueEntity* newTail = new QueueEntity(data);
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
    }

    void pop_front() {
        if(head == nullptr) {
            throw std::out_of_range("Queue is empty");
            return;
        }

        QueueEntity* newHead = head->next;
        delete head;
        head = newHead;
    }

    void pop_back() {
        if(tail == nullptr) {
            throw std::out_of_range("Queue is empty");
            return;
        }

        QueueEntity* newTail = tail->prev;
        delete tail;
        tail = newTail;
    }

    void* front() {
        if(head == nullptr) {
            throw std::out_of_range("Queue is empty");
            return nullptr;
        }

        return head->data;
    }

    void* back() {
        if(tail == nullptr) {
            throw std::out_of_range("Queue is empty");
            return nullptr;
        }

        return tail->data;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        while(head != nullptr) {
            QueueEntity* newHead = head->next;
            delete head;
            head = newHead;
        }
    }
};

int main() {
    // std::ios_base::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);

    int z, n, m, d;
    Node** nodes_a;
    Node** nodes_b;
    Node* dummy;

    cin >> z;
    for(; z>0; z--) {
        cin >> n >> m;
        nodes_a = new Node*[n];
        nodes_b = new Node*[m];
        for(int i = 0; i < n; i++) {
            d = -1;
            nodes_a[i] = new Node();

            while(d != i) {
                cin >> d;
                
            }
            
        }
        for(int i = 0; i < m; i++) {
            d = -1;
            nodes_b[i] = new Node();
            while(d != i) {
                cin >> d;
            }
        }
    }

    return 0;
}