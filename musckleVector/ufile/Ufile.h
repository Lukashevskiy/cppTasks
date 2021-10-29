//
// Created by dmitriy on 28.10.2021.
//

#ifndef MUSCKLEVECTOR_UFILE_H
#define MUSCKLEVECTOR_UFILE_H
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include "UfileElement.h"

class Ufile {
private:
    std::string file_name;
    std::vector<UfileElement> data;
public:
    Ufile();
    Ufile(const Ufile &ufile);
    explicit Ufile(std::string new_filename);
    Ufile(std::string new_filename, std::vector<UfileElement> &new_data);
    void append_element(const UfileElement& ufileElement);
    Ufile &operator+=(Ufile &ufile);
    Ufile &operator+(Ufile &ufile);
    Ufile &operator-=(Ufile &ufile);
    Ufile &operator-(Ufile &ufile);
    UfileElement &operator[](unsigned long index) const;
    void read_file(char delimiter);
    void write_file(bool isContinue);
    friend std::ostream& operator<<(std::ostream &out, const Ufile &ufile);
};


#endif //MUSCKLEVECTOR_UFILE_H
