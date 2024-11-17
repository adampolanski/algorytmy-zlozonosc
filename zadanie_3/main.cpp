#include <iostream>

using std::cin, std::cout;

struct PrefixField {
    int x_size, y_size;
    long long** tab;
    long long** prefix_sum;

    PrefixField(int x_size, int y_size) {
        this->x_size = x_size;
        this->y_size = y_size;
        tab = new long long*[x_size + 1];                          //  0 - x_size+1
        prefix_sum = new long long*[x_size + 1];                   // -1 - x_size

        for(int i = 0; i < x_size + 1; i++) {
            tab[i] = new long long[y_size + 1] {0};                //  0 - y_size+1
            prefix_sum[i] = new long long[y_size + 1] {0};         // -1 - y_size
        }
    }

    void add(int x1, int y1, int x2, int y2, unsigned long long w) {
        tab[x1][y1] += w;
        tab[x2+1][y2+1] += w;
        tab[x1][y2+1] -= w;
        tab[x2+1][y1] -= w;
    }

    void calculate_prefix_sum() {
        for(int i = 1; i < x_size + 1; i++) {
            for(int j = 1; j < y_size + 1; j++) {
                prefix_sum[i][j] = tab[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
            }
        }

        for(int i = 1; i < x_size + 1; i++) {
            for(int j = 1; j < y_size + 1; j++) {
                prefix_sum[i][j] = prefix_sum[i][j] + prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1];
            }
        }
    }

    long long get(int x1, int y1, int x2, int y2) {
        return prefix_sum[x2+1][y2+1] - prefix_sum[x1][y2+1] - prefix_sum[x2+1][y1] + prefix_sum[x1][y1];
    }

    void clear() {
        for(int i = 0; i < x_size + 1; i++) {
            for(int j = 0; j < y_size + 1; j++) {
                tab[i][j] = 0;
                prefix_sum[i][j] = 0;
            }
        }
    }

    ~PrefixField() {
        for(int i = 0; i < x_size + 1; i++) {
            delete[] tab[i];
            delete[] prefix_sum[i];
        }

        delete[] tab;
        delete[] prefix_sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int g, n, m;
    cin >> g >> n >> m;

    PrefixField field(n, m);

    int k, z, x1, y1, x2, y2;
    long long w;
    for(int i = 0; i < g; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> x1 >> y1 >> x2 >> y2 >> w;
            field.add(x1, y1, x2, y2, w);
        }
        field.calculate_prefix_sum();

        cin >> z;
        for(int j = 0; j < z; j++) {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << field.get(x1, y1, x2, y2) << " ";
        }

        field.clear();
        cout << "\n";
    }

    return 0;
}