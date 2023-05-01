#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Spell {
public:
    int power;
    int mana;
    Spell() {
        this->power = 0;
        this->mana = 0;
    }
    Spell(int pow, int man) {
        this->power = pow;
        this->mana = man;
    }
    ~Spell() {}
};
bool operator < (Spell& n1, Spell& n2) {
    return n1.mana < n2.mana;
}
bool operator > (Spell& n1, Spell& n2) {
    return n1.mana > n2.mana;
}
bool comp(Spell n1, Spell n2) {
    if (n1.power == n2.power) return n1.mana < n2.mana;
    else return n1.power < n2.power;
}

int main() {
    Spell shrapnel(25, 75);
    Spell assassinate(320, 175);
    Spell god(320, 9999);

    cout << "Spell comparison:" << endl;

    bool g = shrapnel < assassinate;
    bool b = god < assassinate;
    cout << g << endl;
    cout << b << endl;

    vector<Spell> vect;
    vect.push_back(god);
    vect.push_back(shrapnel);
    vect.push_back(assassinate);

    cout << endl << "Original vector 1:" << endl;
    for (auto elem : vect) {
        cout << elem.power << " " << elem.mana << ",  ";
    }
    cout << endl;

    cout << endl << "Sorted vector 1:" << endl;
    sort(vect.begin(), vect.end(), comp); //fast sort
    for (auto elem : vect) {
        cout << elem.power << " " << elem.mana << ",  ";
    }
    cout << endl;

    vector<Spell> vect1;
    vect1.push_back(god);
    vect1.push_back(shrapnel);
    vect1.push_back(assassinate);

    cout << endl << "Original vector 2 (same as vector 1):" << endl;
    for (auto elem : vect1) {
        cout << elem.power << " " << elem.mana << ",  ";
    }
    cout << endl;

    for (auto elem : vect1) { //bubble sort
        for (int i(0); i < vect1.size() - 1; i++) {
            if (comp) {
                int temp = vect1[i].power;
                vect1[i].power = vect1[i + 1].power;
                vect1[i + 1].power = temp;

                int temp1 = vect1[i].mana;
                vect1[i].mana = vect1[i + 1].mana;
                vect1[i + 1].mana = temp1;
            }
        }
    }

    cout << endl << "Sorted vector 2 (same as vector 1):" << endl;
    for (auto elem : vect) {
        cout << elem.power << " " << elem.mana << ",  ";
    }
}
