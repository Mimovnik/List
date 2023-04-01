#include <iostream>

#include "List.hpp"

class Klasa {
   private:
    int* ind = nullptr;

   public:
    Klasa();
    Klasa(int ind);
    Klasa(const Klasa& other) { ind = other.ind; }
    Klasa& operator=(const Klasa& other) {
        ind = new int(*other.ind);
        return *this;
    }
    Klasa(Klasa&& other) { ind = other.ind; }
    Klasa& operator=(Klasa&& other) {
        int* tmp = ind;
        ind = other.ind;
        other.ind = ind;
        return *this;
    }
};
Klasa::Klasa() { this->ind = new int(-1); }
Klasa::Klasa(int ind) { this->ind = new int(ind); }

int main() {
    List<Klasa> l;
    Klasa k = Klasa(2);
    l.append(Klasa(1));
    l.append(k);
    Klasa k2 = l.getAt(1);
    return 0;
}