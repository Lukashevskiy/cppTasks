//
// Created by dmitriy on 28.10.2021.
//

#include "Ufile.h"

#include <utility>

Ufile::Ufile() {
    this->file_name = "data.txt";
}

Ufile::Ufile(const Ufile &ufile) {
    this->file_name = ufile.file_name;
    this->data = ufile.data;
}


Ufile::Ufile(const std::string& new_filename) {
    this->file_name = new_filename;

}

Ufile::Ufile(std::string new_filename, std::vector<UfileElement> &new_data) {
    this->file_name = std::move(new_filename);
    this->data = std::move(new_data);
}

Ufile &Ufile::operator+=(Ufile &ufile) {
    for(auto &itemNewUfile: ufile.data){
        for(auto &itemThis: this->data){
            if(itemNewUfile != itemThis){
                this->data.push_back(itemNewUfile);
                this->write_file(true);
            }
        }
    }
    return *this;
}

Ufile &Ufile::operator+(Ufile &ufile) {
    return operator+=(ufile);
}

Ufile &Ufile::operator-=(Ufile &ufile) {
    for(auto &itemNewUfile: ufile.data){
        for(int i = 0; i < this->data.size(); i++){
            if(itemNewUfile == this->data[i]){
                this->data.erase(this->data.cbegin()+i);
            }
        }
    }
    this.write_file(false);
    return *this;
}

Ufile &Ufile::operator-(Ufile &ufile) {
    return operator-=(ufile);
}

void Ufile::read_file(char delimiter) {
    std::ifstream fin(this->file_name);
    if (!fin.is_open()) {
        throw std::exception();
    }
    std::string buffer;
    while (getline(fin, buffer)) {
        UfileElement ufileElement(buffer, delimiter);
        this->data.push_back(ufileElement);
    }
}

void Ufile::write_file(bool isContinue) {
    std::ofstream fout;
    if(isContinue){
        fout.open(this->file_name, std::ios::app);
    }else{
        fout.open(this->file_name);
    }
    if(!fout.is_open()){
        throw std::exception();
    }
    for(auto & i: this->data){
        fout << i;
    }
}

std::ostream &operator<<(std::ostream &out, const Ufile &ufile) {
    out << "File name - " << ufile.file_name << std::endl;
    for(auto &str: ufile.data){
        out << str << std::endl;
    }
    return out;
}