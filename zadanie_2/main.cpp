#include <iostream>
#include <math.h>

using std::cin, std::cout;

struct Szlachcic {
    char name;
    int size;
    int* codes;

    Szlachcic(){};

    Szlachcic(char name, int size) {
        this->name = name;
        this->size = size;
        codes = new int[size];

        for(int i = 0; i < size; i++) {
            cin >> codes[i];
        }
    }

    void radixSort() {
        const int MAX_VALUE = 120000;
        int exp = 1;
        int* output = new int[size];
        while (MAX_VALUE / exp > 0) {
            int count[10] = {0};

            for (int i = 0; i < size; i++) {
                count[(codes[i] / exp) % 10]++;
            }

            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }

            for (int i = size - 1; i >= 0; i--) {
                output[count[(codes[i] / exp) % 10] - 1] = codes[i];
                count[(codes[i] / exp) % 10]--;
            }

            for (int i = 0; i < size; i++) {
                codes[i] = output[i];
            }

            exp *= 10;
        }
        delete[] output;
    }

    void toString() {
        cout << name << ": ";
        for(int i = 0; i < size; i++) {
            cout << codes[i] << " ";
        }
        cout << "\n";
    }

    ~Szlachcic() {
        delete[] codes;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    Szlachcic** list = new Szlachcic*[n];
    char s;
    int i;
    for(int iter = 0; iter < n; iter++) {
        cin >> s >> i;
        list[iter] = new Szlachcic(s, i);
        list[iter]->radixSort();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j]->name > list[j + 1]->name) {
                Szlachcic* temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        list[i]->toString();
    }

    delete[] list;

    return 0;
}
