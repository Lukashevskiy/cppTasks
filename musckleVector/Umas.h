//
// Created by dmitriy on 08.10.2021.
//

#ifndef MUSCKLEVECTOR_UMAS_H
#define MUSCKLEVECTOR_UMAS_H
#include <istream>
#include <string>

#define CAPACITY_DEFAULT_SIZE 1000
#define CAPACITY_DELTA 1000
class ExceptionUmas {};

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


#endif //MUSCKLEVECTOR_UMAS_H
