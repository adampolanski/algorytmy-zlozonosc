#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

struct Pair {
    string key;
    int count;
    Pair() {}
    Pair(string key) {
        this->key = key;
        this->count = 1;
    }
};

struct Node {
    string key;
    vector<Pair> values;
    Node *left, *right, *parent;

    Node() {}
    Node(string key) {
        this->key = key;
        this->values = vector<Pair>();
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    void addValue(string key) {
        if(values.empty()) {
            values.push_back(Pair(key));
            return;
        }
        for(auto iter = values.begin(); iter != values.end(); iter++) {
            if((*iter).key < key) {
                continue;
            } else if((*iter).key == key) {
                (*iter).count++;
                return;
            } else {
                values.insert(iter, Pair(key));
                return;
            }
        }
        values.push_back(Pair(key));
    }

    void debug() {
        cout << "Node " << key << ":\n";
        for(auto &value : values) {
            cout << "  " << value.key << "(" << value.count << ")\n";
        }
    }

    bool operator==(const Node &node) {
        return this->key == node.key;
    }

    ~Node() {
        if(left != nullptr) {
            delete left;
        }
        if(right != nullptr) {
            delete right;
        }
    }
};

struct SplayTree {
    Node *root;

    SplayTree() {
        root = nullptr;
    }

    void insert(string key, string value) {
        if(root == nullptr) {
            root = new Node(key);
            root->addValue(value);
            return;
        }

        Node *current = root;
        while(true) {
            if(current->key == key) {
                current->addValue(value);
                return;
            } else if(current->key < key) {
                if(current->right == nullptr) {
                    current->right = new Node(key);
                    current->right->addValue(value);
                    current->right->parent = current;
                    return;
                }
                current = current->right;
            } else {
                if(current->left == nullptr) {
                    current->left = new Node(key);
                    current->left->addValue(value);
                    current->left->parent = current;
                    return;
                }
                current = current->left;
            }
        }
    }

    Node* findByKey(string key) {
        Node* current = root;
        Node* previous = nullptr;
        while(current != nullptr) {
            if(current->key == key) {
                return current;
            } else if(current->key < key) {
                // previous = current;
                current = current->right;
            } else {
                // previous = current;
                current = current->left;
            }
        }
        return previous;
    }

    void printByKey(string key) {
        Node* node = findByKey(key);
        if(node == nullptr) {
            return;
        } else {
            for(auto &value : node->values) {
                cout << value.key << "(" << value.count << ") ";
            }
            cout << "\n";
        }
    }

    ~SplayTree() {
        delete root;
    }
};

int main() {
    // std::ios_base::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);

    int n;
    cin >> n;
    char op;
    string p, s, x;
    SplayTree* sTree = new SplayTree();
    SplayTree* pTree = new SplayTree();
    for(; n > 0; n--) {
        cin >> op;
        switch(op) {
            case 'd':{
                cin >> p >> s;
                sTree->insert(s, p);
                pTree->insert(p, s);
                break;
            }
            case 's':{
                cin >> x;
                sTree->printByKey(x);
                break;
            }
            case 'p':{
                cin >> x;
                pTree->printByKey(x);
                break;
            }
            default:{
                cout << "Input error\n";
                break;
            }
        }
    }

    delete sTree;
    delete pTree;

    return 0;
}