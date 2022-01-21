#include <iostream>
#include "Function.h"
#include <vector>
#include <string>
#include <ostream>
#include <random>
#include "Parabola.h"
#include "Exponential.h"
#include "Hyperbola.h"
using namespace std;

ostream &operator<<(ostream &out, const Function& f ){
    out << f.get_type() << "\n";
    return out;
}

int main() {
    vector<string> function_types{
        "Base",
        "Parabola",
        "Hyperbola",
        "Exponential"
    };

    vector<Function*> funcs(10);
    for(int i = 0; i < 10; i++){
        switch (random()% (function_types.size()-1) + 1) {
            case 1:
                funcs[i] = new Parabola(0, 0);
                break;
            case 2:
                funcs[i] = new Hyperbola(0, 0);
                break;
            case 3:
                funcs[i] = new Exponential(0, 0);
                break;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << funcs[i]->get_type() << "\n";
    }

    return 0;
}
