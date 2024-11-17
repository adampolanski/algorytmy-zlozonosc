#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int _INT_MAX = 2147483647;

struct Pair {
    int key;
    int count;
    Pair* next;
    Pair() {
        this->key = -1;
        this->count = _INT_MAX;
        this->next = nullptr;
    }
    Pair(int key, int value) {
        this->key = key;
        this->count = value;
        this->next = nullptr;
    }
    Pair(int key, int value, Pair* next) {
        this->key = key;
        this->count = value;
        this->next = next;
    }
};

struct Node {
    int id;
    Pair* pathRoot;

    Node(int id, int size) {
        this->id = id;
        this->pathRoot = nullptr;
    }

    void add_path(Pair* path) {
        if(this->pathRoot == nullptr) {
            this->pathRoot = path;
        } else {
            while(this->path != nullptr) {
                if(this->path.value > path.value) {
                    Pair temp = this->paths[i];
                    this->paths[i] = path;
                    path = temp;
                }
            }
            if(i < sizeof(paths)) {
                this->paths[i] = path;
            } else {
                cout << "Error: i >= sizeof(paths)\n";
            }
        }
    }

    Pair get_min_path(Node** nodes) {
        for(int i = 0; this->paths[i].key != -1, i < sizeof(paths); i++) {
            if(nodes[this->paths[i].key] == nullptr) {
                return this->paths[i];
            }
        }
        return Pair(-1, _INT_MAX);
    }

    void print() {
        cout << "Node " << this->id << ":\n";
        for(int i = 0; this->paths[i].key != -1, i < sizeof(paths); i++) {
            cout << "  " << this->paths[i].key << " -> " << this->paths[i].value << "\n";
        }
    }
};

int fun(Node** nodes, Node* node, int size) {
int sum = 0;

    Node** nodes_visited_tab = new Node*[size];
    for(int i = 0; i < size; i++) {
        nodes_visited_tab[i] = nullptr;
    }

    int nodes_visited = 1;
    nodes_visited_tab[node->id] = node;

    while (nodes_visited < size) {
        Pair min_path = Pair(-1, _INT_MAX);
        for(int i = 0; i < size; i++) {
            if(nodes_visited_tab[i] != nullptr) {
                Pair path = nodes_visited_tab[i]->get_min_path(nodes_visited_tab);
                if(path.count < min_path.count) {
                    min_path = path;
                }
            }
        }

        if(min_path.key == -1) {
            cout << "Error: min_path.key == -1\n";
            break;
        }

        nodes_visited_tab[min_path.key] = nodes[min_path.key];
        nodes_visited++;
        sum += min_path.count;

        // cout << "DEBUG: " << min_path.key << " -> " << min_path.value << "\n";
        // for(int i = 0; i < size; i++) {
        //     if(nodes_visited_tab[i] != nullptr) {
        //         cout << nodes_visited_tab[i]->id << " ";
        //     } else {
        //         cout << "X ";
        //     }
        // }
        // cout << "\n";
    }

    return sum;
}

int main() {
    // std::ios_base::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Node** nodes = new Node*[n];

    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i, m);
    }

    for(int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        nodes[a]->add_path(Pair(b, d));
        nodes[b]->add_path(Pair(a, d));
        // nodes[a]->print();
        // nodes[b]->print();
    }

    cout << fun(nodes, nodes[0], n) << "\n";

    // for(int i = 0; i < n; i++) {
    //     nodes[i]->print();
    // }

    for(int i = 0; i < n; i++) {
        delete nodes[i];
    }
    delete[] nodes;

    return 0;
}