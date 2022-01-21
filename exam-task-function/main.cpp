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
        "Exponential",

    };

    vector<Function*> funcs(10);
    for(int i = 0; i < 10; i++){
        switch (random()% (function_types.size()-1) + 1) {
            case 1:
                funcs[i] = new Parabola(1);
                break;
            case 2:
                funcs[i] = new Hyperbola(1);
                break;
            case 3:
                funcs[i] = new Exponential(1);
                break;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << "-----------------------------------\n";
        cout << "start func\n";
        cout << funcs[i]->get_expression() << '\n';
        cout << "integral of start func\n";
        cout << funcs[i]->integral()->get_expression() << " + C\n";
        cout << "diff of start func\n";
        cout << funcs[i]->differential()->get_expression() << "\n";
        cout << "maximum of start func\n";
        cout << funcs[i]->max_of_func(-10, 10) << "\n";
        cout << "minimum of start func\n";
        cout << funcs[i]->min_of_func(-10, 10) << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
