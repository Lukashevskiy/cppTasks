#include <iostream>
#include "rational.h"

using namespace std;

int main(){

    Rational a(1,2);
    Rational b(3, 4);
    cout << a;
    cout << endl;
    cout << b;
    cout << endl;
    Rational c = a+b;
    //a = a + b;
    cout << a+b;

    return 0;
}
