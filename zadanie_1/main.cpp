#include <iostream>

const unsigned long long v_mod[6] = {4294967296, 3486784401, 1220703125, 1977326743, 2357947691, 815730721};

void add(unsigned long long *v, unsigned long long a){
    for(int i = 0; i < 6; i++){
        v[i] += a;
        v[i] %= v_mod[i];
    }
}

void mul(unsigned long long *v, unsigned long long a){
    for(int i = 0; i < 6; i++){
        v[i] *= a;
        v[i] %= v_mod[i];
    }
}

bool compare(unsigned long long *v1, unsigned long long *v2){
    for(int i = 0; i < 6; i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int p;
    std::cin >> p;

    unsigned long long v1[6] = {0, 0, 0, 0, 0, 0};
    unsigned long long v2[6] = {0, 0, 0, 0, 0, 0};

    for(int i = 0; i < p; i++){
        int n, z, a;
        
        std::cin >> n;
        for(int j = 0; j < n; j++){
            std::cin >> z >> a;
            if(z == 0){
                add(v1, a);
            } else {
                mul(v1, a);
            }
        }

        std::cin >> n;
        for(int j = 0; j < n; j++){
            std::cin >> z >> a;
            if(z == 0){
                add(v2, a);
            } else {
                mul(v2, a);
            }
        }

        if(compare(v1, v2)){
            std::cout << "rowne\n";
        } else {
            std::cout << "rozne\n";
        }

        for(int j = 0; j < 6; j++){
            v1[j] = 0;
            v2[j] = 0;
        }
    }

    return 0;
}