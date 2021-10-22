//
// Created by dmitriy on 08.10.2021.
//

#include "Umas.h"
#include <istream>
#include <cstring>


Umas::Umas() {
    this->size = 0;
    this->capacity = CAPACITY_DEFAULT_SIZE;
    this->ptr = new int[this->capacity];
}

Umas::Umas(unsigned int new_size) {
    if(new_size<0){
        throw ExceptionUmas();
    }
    this->size = new_size;
    this->capacity = new_size;
    this->ptr = new int[new_size];
}

Umas::Umas(unsigned int new_size, const int *mas){
    if(new_size<=0){
        throw ExceptionUmas();
    }
    this->size = new_size;
    this->capacity = new_size;
    memcpy(this->ptr, mas, new_size * sizeof *mas);

}

Umas& Umas::insert(unsigned int index, int elements) {
    if (0 > index || this->size + 1 < index) {
        throw ExceptionUmas();//костыль
    }

    if (this->capacity < this->size + 1) {
        change_capacity(this->capacity + CAPACITY_DELTA);
    }

    this->size++;

    for (unsigned int i = this->size - 1; i > index; i--) {
        this->ptr[i] = this->ptr[i - 1];
    }

    ptr[index] = elements;
    return *this;
}

Umas&  Umas::insert_back(int element) {
    this->insert(this->size, element);
    return *this;
}

Umas&  Umas::insert_mas(int index, unsigned int m_size, const int *mas) {
    if(index < 0 || index >= this->size){
        throw ExceptionUmas();
    }
    change_capacity(this->capacity+m_size);
    this->size += m_size;

    for(int i = index; i<this->size; i++){
        this->ptr[i+m_size] = this->ptr[i];
    }

    for(int i = 0; i< m_size; i++){
        this->ptr[i+index] = mas[i];
    }
    return *this;
}

Umas&  Umas::remove(unsigned int index) {
    if (index < 0 || index > this->size)
        throw ExceptionUmas();//костыль

    for (unsigned int i = index + 1; i < this->size; i++)
        this->ptr[i - 1] = this->ptr[i];


    this->ptr[this->size - 1] = 0;
    this->size = -1;
    return *this;
}

Umas&  Umas::remove_back() {
    remove(this->size - 1);
    return *this;
}

void Umas::change_capacity(unsigned int new_capacity) {
    if (new_capacity < this->capacity)
        throw ExceptionUmas();

    int *buff = new int[new_capacity];
    this->capacity = new_capacity;

    delete[] this->ptr;

    memcpy(buff, this->ptr, this->size * sizeof *this->ptr);


    this->ptr = buff;
}

int Umas::operator[](int index){
    if(index < 0 || this->size <= index){
        throw ExceptionUmas();
    }
    return this->ptr[index];
}


Umas &Umas::operator=(const Umas& mas){
    if(&mas != this) {
        this->size = mas.size;
        this->capacity = mas.capacity;
        delete[] ptr;
        memcpy(this->ptr, mas.ptr, mas.size * sizeof *mas.ptr);
    }
    return *this;
}

Umas &Umas::operator-() {
    for(int i = 0; i < this->size; i++){
        this->ptr[i] = -this->ptr[i];
    }
    return *this;
}

Umas& Umas::operator+(Umas &mas) {
    if(mas.size != this->size){
        throw ExceptionUmas();
    }
    for(int i = 0; i < this->size; i++){
        this->ptr[i] += mas.ptr[i];
    }
    return *this;
}

Umas& Umas::operator*(int k) {
    for(int i = 0; i < this->size; i++){
        this->ptr[i] *= k;
    }
    return *this;
}
int Umas::get_size() const{
    return this->size;
}

Umas::~Umas() {
    this->capacity = 0;
    this->size = 0;
    delete[] ptr;
}

std::ostream &operator<<(std::ostream &out, const Umas &mas) {
    out << "Amount of elements - " << mas.size << "\n" << "Elements = [";
    if(mas.size == 0){
        out << "Null]\n";
        return out;
    }
    for (int i = 0; i < mas.size - 1; i++) {
        out << mas.ptr[i] << ", ";
    }
    out << mas.ptr[mas.size - 1];
    out << "]\n";
    return out;

}

