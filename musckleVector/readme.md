### В этом проекте два своих типа данных Umas - вектор, Umatrix - матрица
## Вектор
### Umas.cpp Umas.h
```c++
class Umas{
private:

    unsigned int size;
    unsigned int capacity;
    int *ptr;

    void change_capacity(unsigned int new_capacity);

public:

    Umas();
    explicit Umas(unsigned int size);
    Umas(unsigned int size, const int *mas);

    Umas& insert(unsigned int index, int elements);
    Umas& insert_back(int element);
    Umas& insert_mas(int index, unsigned int m_size, const int *mas);
    Umas& remove(unsigned int index);
    Umas& remove_back();
    int get_size() const;
    int operator[](int index);
    ~Umas();

    Umas& operator=(const Umas& mas);
    Umas& operator-();
    Umas& operator+(Umas &mas);
    Umas& operator*(int k);

    friend std::ostream& operator<<(std::ostream &out, const Umas &mas);
};
```
## Матрица
### Umatrix.cpp Umatrix.h
#### Что есть
    конструкторы с различными параметрами
        с одним размером
        без указания размера
        с указанием размера и вектор
        вектор
    Перегружены операторы
        +
        +=
        -
        -=
        *
    Вычисляется минор по строке и слобцу, алгебраическое дополнение по строке и столбцу
    Вычисляется матрица алгебраических дополнений
    Вычисляется транспонирование матрицы
    Определитель матрицы
    Обратная матрица
    p.s далее бы хотелось мигрировать на свой вектор.
```c++
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
```
