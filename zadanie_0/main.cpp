#include <iostream>
#include <string>

std::string find_profession(char p);
void jaroslaw(char p);
void bronislaw(char p);
void unrecognized();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    char s, p;
    std::cin >> s >> p;

    switch(s) {
        case 'J':{
            jaroslaw(p);
            break;
        }
        case 'B':{
            bronislaw(p);
            break;
        }
        default:{
            unrecognized();
        }
    }

    return 0;
}

std::string find_profession( char p){
    std::string profession = "";
    switch(p) {
        case 'K':{
            profession = "kowalu";
            break;
        }
        case 'M':{
            profession = "młynarzu";
            break;
        }
        case 'G':{
            profession = "garbarzu";
            break;
        }
        case 'T':{
            profession = "tkaczu";
            break;
        }
        case 'R':{
            profession = "rybaku";
            break;
        }
        case 'S':{
            profession = "szewcu";
            break;
        }
        case 'W':{
            profession = "wróżbiarzu";
            break;
        }
        case 'P':{
            profession = "programisto";
            break;
        }
        case 'I':{
            profession = "influencerze";
            break;
        }
        default:{
            profession = "-";
        }
    }
    return profession;
}

void jaroslaw(char p) {
    std::string profession = find_profession(p);
    if(profession == "-"){
        unrecognized();
        return;
    }

    std::cout << "Bądź zdrów " << profession << ", chłopie Jarosława!\n";
    return;
}

void bronislaw(char p) {
    std::string profession = find_profession(p);
    if(profession == "-"){
        unrecognized();
        return;
    }

    std::cout << "Idź precz pachołku Bronisława!\n";
    return;
}

void unrecognized() {
    std::cout << "Czego tu szukasz przybłędo?\n";
    return;
}