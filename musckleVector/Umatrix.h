//
// Created by dmitriy on 14.10.2021.
//

#ifndef MUSCKLEVECTOR_UMATRIX_H
#define MUSCKLEVECTOR_UMATRIX_H
#include <vector>
#include <istream>
#include <iostream>

class Umatrix {
    std::vector < std::vector<double> > matrix; //с вектора будет проще мигрировать на свой вектор
    unsigned int n, m;
public:
    Umatrix();
    Umatrix(unsigned int n, unsigned int m);
    Umatrix(unsigned int n, std::vector<std::vector<double>> vec);
    explicit Umatrix(std::vector<std::vector<double> > vec);
    explicit Umatrix(unsigned int n);
    Umatrix(Umatrix& copyedMatrix);

    Umatrix &operator=(const Umatrix &matrix);
    Umatrix &operator*(Umatrix& umatrix);
    Umatrix &operator*(double k);
    Umatrix &operator-();
    Umatrix &operator+=(Umatrix& umatrix);
    Umatrix &operator+(Umatrix& umatrix);
    Umatrix &operator-=(Umatrix &umatrix);
    Umatrix &operator-(Umatrix &umatrix);
    std::vector<double> operator[](unsigned long index) const;

    Umatrix& transpose(); //транспонирование матрицы

    [[nodiscard]] unsigned int get_size_n() const;
    [[nodiscard]] unsigned int get_size_m() const;
    Umatrix minor(unsigned int  i_e, unsigned  int j_e); //минор по строке и столбцу(определитель)
    Umatrix algebraic_adjunct(unsigned int i_e, unsigned int j_e); //алгебраическое дополнение по строке и столбцу (определитель)
    Umatrix matrix_of_algebraic_adjunct();
    Umatrix operation_det_multiply(int i_e, double k); //операция умножение определенной строки (определитель)
    void invertible(double &determinant, Umatrix &umatrix);
    friend std::ostream &operator<<(std::ostream &out, const Umatrix &matrix);

};
double det(Umatrix umatrix);
#endif //MUSCKLEVECTOR_UMATRIX_H
