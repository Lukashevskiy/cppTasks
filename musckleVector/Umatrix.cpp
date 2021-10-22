//
// Created by dmitriy on 14.10.2021.
//

#include "Umatrix.h"

#include <utility>
#define DEFAULT_MATRIX_SIZE 1

Umatrix::Umatrix() {
    this->n = DEFAULT_MATRIX_SIZE;
    this->m = DEFAULT_MATRIX_SIZE;

    this->matrix.resize(DEFAULT_MATRIX_SIZE);
    for(unsigned int i = 0; i < DEFAULT_MATRIX_SIZE; i++){
        this->matrix[i].resize(DEFAULT_MATRIX_SIZE, 1);
    }
}

Umatrix::Umatrix(unsigned int new_n, unsigned int new_m) {
    this->n = new_n;
    this->m = new_m;
    this->matrix.resize(n);
    for(unsigned int i = 0; i < n; i++){
        this->matrix[i].resize(m);
    }
}

Umatrix::Umatrix(unsigned int new_n) {
    this->n = new_n;
    this->m = new_n;
    this->matrix.resize(n);
    for(unsigned int i = 0; i < n; i++){
        this->matrix[i].resize(n);
    }
    for(int i = 0; i < n; i++){
        this->matrix[i][i] = 1;
    }
}

Umatrix::Umatrix(unsigned int new_n, std::vector<std::vector<double>> vec) {
    this->n = new_n;
    this->m = new_n;
    this->matrix = std::move(vec);
}

Umatrix::Umatrix(std::vector<std::vector<double> > vec) {
    this->n = vec.size();
    this->m = vec[0].size();
    this->matrix = std::move(vec);
}

Umatrix::Umatrix(Umatrix &copyedMatrix) {
    this->n = copyedMatrix.n;
    this->m = copyedMatrix.m;

    //вернуться, когда мигрирую на свой вектор
    this->matrix = copyedMatrix.matrix;
}

std::ostream &operator<<(std::ostream &out, Umatrix &matrix) {
    out << "size matrix = (" << matrix.n << ", " << matrix.m << ")\n";
    for(unsigned int i = 0; i < matrix.n; i++){
        out << "( ";
        for(unsigned int j = 0; j < matrix.m-1; j++){
            out << matrix.matrix[i][j] << ", ";
        }
        out << matrix.matrix[i][matrix.m-1] << " )\n";
    }
    return out;
}

Umatrix &Umatrix::operator=(const Umatrix &other) {
    if(this != &other){
        this->n = other.n;
        this->m = other.m;
        //посмотреть сюда когда мигрирую на свой класс
        this->matrix = other.matrix;
    }
    return *this;
}

Umatrix& Umatrix::transpose(){
    Umatrix ans(this->m, this->n);
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            ans.matrix[j][i] = this->matrix[i][j];
        }
    }
    *this = ans;
    return *this;
}

Umatrix Umatrix::minor(unsigned int  i_e, unsigned  int j_e){
    if((i_e < 0 || j_e < 0) || (i_e >= this->n || j_e >= this->m)){
        throw std::exception();
    }
    Umatrix ans(this->n-1);
    unsigned int i_ans = 0, j_ans = 0;
    for(int i = 0; i < this->n; i++){
        if(i != i_e) {
            for (int j = 0; j < this->m; j++) {
                if (j != j_e) {
                    ans.matrix[i_ans][j_ans] = this->matrix[i][j];
                    j_ans++;
                }
            }
            j_ans = 0;
            i_ans++;
        }
    }
    return ans;
}

Umatrix Umatrix::algebraic_adjunct(unsigned int i_e, unsigned int j_e) {
    Umatrix minor = this->minor(i_e, j_e);
    if( (i_e+1 + j_e+1) % 2 == 1)
        minor.operation_det_multiply(0,-1);

    return minor;
}

Umatrix Umatrix::operation_det_multiply(int i_e, double k) {
    if(i_e < 0 || i_e >= this->n){
        throw std::exception();
    }
    for(int i = 0; i < this->m; i++){
        this->matrix[i_e][i] *= k;
    }
    return *this;
}

double Umatrix::get_element_matrix(unsigned int i, unsigned int j) {
    if((i < 0 || j < 0) || (i >= this->n || j >= this->m)){
        throw std::exception();
    }
    return this->matrix[i][j];
}

unsigned int Umatrix::get_size_m() const {
    return this->m;
}

unsigned int Umatrix::get_size_n() const {
    return this->n;
}

Umatrix Umatrix::matrix_of_algebraic_adjunct() {
    if(this->n>2) {
        Umatrix ans = Umatrix(this->n);
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                ans.matrix[i][j] = det(algebraic_adjunct(i, j));
            }
        }
        return ans;
    }else if(this->n == 2){
        return Umatrix(std::vector<std::vector<double> >{{this->matrix[1][1], -this->matrix[0][1]},{-this->matrix[1][0], this->matrix[0][0]}});
    }else{
        throw std::exception();
    }
}

void Umatrix::invertible(double &determinant, Umatrix &umatrix) {
    if(this->n != this->m){
        throw std::exception();
    }
    double dt = det(*this);
    if(dt == 0){
        throw std::exception();
    }else{
        umatrix = this->matrix_of_algebraic_adjunct();
        umatrix = umatrix.transpose();
        determinant = dt;
    }
}

Umatrix &Umatrix::operator*(Umatrix &umatrix) {
    if(this->m != umatrix.n){
        throw std::exception();
    }
    Umatrix ans(this->n, umatrix.m);
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < umatrix.m; j++){
            for(int k = 0; k < this->m; k++){
                ans.matrix[i][j] += this->matrix[i][k] * umatrix.matrix[k][j];
            }
        }
    }
    *this = ans;
    return *this;
}
Umatrix &Umatrix::operator*(double k) {
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            this->matrix[i][j] *= k;
        }
    }
    return *this;
}

Umatrix &Umatrix::operator-() {
    return this->operator*(-1);
}

Umatrix &Umatrix::operator+=(Umatrix &umatrix){
    if(this->n != umatrix.n || this->m != umatrix.m){
        throw std::exception();
    }
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            this->matrix[i][j] += umatrix.matrix[i][j];
        }
    }
    return *this;
}

Umatrix &Umatrix::operator+(Umatrix &umatrix) {
    return this->operator+=(umatrix);
}

Umatrix &Umatrix::operator-=(Umatrix &umatrix){
    if(this->n != umatrix.n || this->m != umatrix.m){
        throw std::exception();
    }
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            this->matrix[i][j] -= umatrix.matrix[i][j];
        }
    }
    return *this;
}

Umatrix &Umatrix::operator-(Umatrix &umatrix) {
    return this->operator-=(umatrix);
}

double det(Umatrix umatrix){
    if(umatrix.get_size_n() == 1){
        return umatrix.get_element_matrix(0,0);
    }else if(umatrix.get_size_n() == 2){
        return (umatrix.get_element_matrix(0,0) * umatrix.get_element_matrix(1,1)) - (umatrix.get_element_matrix(0,1) * umatrix.get_element_matrix(1,0));
    }else{
        std::vector <double> minors;
        minors.resize(umatrix.get_size_n());
        for(int k = 0; k < umatrix.get_size_n(); k++){
            minors[k] = det(umatrix.algebraic_adjunct(0,k)) * umatrix.get_element_matrix(0,k);
        }
        double ans = 0;
        for(int k = 0; k < umatrix.get_size_n(); k++){
            ans += minors[k];
        }
        return ans;
    }
}
