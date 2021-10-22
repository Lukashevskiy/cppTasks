#include <iostream>
#include "Umas.h"
#include "Umatrix.h"

using namespace std;



int main() {

//Тестируем Umatrix
//конструкторы и вывод инициализированных Umatrix
Umatrix m;
Umatrix m1(10);
Umatrix m2(10,2);
Umatrix m3(m1);

vector<vector<double> > vector1;
vector1.resize(5);
int ch = 1;
for(int i = 1; i <= 5; i++){
    vector1[i-1].resize(5);
    for(int j = 1; j <= 5; j++){
        vector1[i-1][j-1] = ch;
        ch++;
    }
}
vector1[0][1] = 100;
vector1[1][4] = -7;
vector1[2][3] = 15;
vector1[3][0] = 11;
vector1[4][2] = 13;
Umatrix m4(5, vector1);
cout << m << m3 << m1 << m2 << m4;
//транспонирование матриц
cout << m2.transpose() << m4.transpose();
//поиск детерминанты, тут сразу проверим и алгебраические дополнения и миноры
//cout << det(m4) << endl;
//поиск минора по столбцу и строке
Umatrix m5 = m4.minor(0,0);
cout << m5;
//поиск обратной матрицы важный момент, если детерминант матрицы 0, то выкинет исключение
vector<vector<double> > v1, v2;
v1 = {{1,2}, {3,4}};
v2 = {{1, 100, 3 , 1}, { 6, 7, 8, -5}, { 11, 12, 13, 54 }, {5, 6, 7, 8} };
Umatrix m10 = Umatrix(v1);
m2 = Umatrix(v2);
double a = 0;
Umatrix ans;
//cout << m10;
m2.invertible(a,ans);
cout << ans << " 1/ " << a << endl;
//проверка уножения матриц
cout << m2*ans << a;
//проверка сложения/вычитания матриц.
cout << m2+ans;
cout << m2-ans;

return 0;

}
