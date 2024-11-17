#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

const int _INT_MAX = 2147483647;

struct Node;

struct Path {
    Node *dest;
    int distance;

    Path(Node *dest, int distance) {
        this->dest = dest;
        this->distance = distance;
    }
};
struct Node {
    vector<Path*> paths;
    bool visited;

    void addPath(Node *dest, int distance) {
        if (paths.empty()) {
            paths.push_back(new Path(dest, distance));
            return;
        } else {
            for (auto iter = paths.begin(); iter != paths.end(); iter++) {
                if ((*iter)->distance < distance) {
                    continue;
                } else {
                    paths.insert(iter, new Path(dest, distance));
                    return;
                }
            }
            paths.push_back(new Path(dest, distance));
        }
    }

    Node() {
        this->visited = false;
    }

    ~Node() {
        for(auto &path : paths) {
            if(path) {
                delete path;
            }
        }

        paths.clear();
    }
};

vector<Path*> findShortestPath(Node **nodes, int n) {
    vector<Path*> result;
    vector<Node*> visitedNodes;
    nodes[0]->visited = true;
    visitedNodes.push_back(nodes[0]);

    int minDistance;
    Path* minPath;

    while(visitedNodes.size() < n) {
        minDistance = _INT_MAX;

        for(auto &node : visitedNodes) {
            for(auto &path : node->paths) {
                if(!path->dest->visited) {
                    if(path->distance < minDistance) {
                        minDistance = path->distance;
                        minPath = path;
                    }
                }
            }
        }

        minPath->dest->visited = true;
        visitedNodes.push_back(minPath->dest);
        result.push_back(minPath);
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Node **nodes = new Node*[n];
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }

    vector<Path*> result;

    for(; m > 0; m--) {
        int a, b, d;
        cin >> a >> b >> d;
        nodes[a]->paths.push_back(new Path(nodes[b], d));
        nodes[b]->paths.push_back(new Path(nodes[a], d));
    }

    result = findShortestPath(nodes, n);

    int resultSum = 0;
    for(auto &path : result) {
        resultSum += path->distance;
    }

    cout << resultSum << "\n";

    for(int i = 0; i < n; i++) {
        delete nodes[i];
    }
    delete[] nodes;

    return 0;
}