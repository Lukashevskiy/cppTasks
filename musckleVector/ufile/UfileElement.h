//
// Created by dmitriy on 28.10.2021.
//

#ifndef MUSCKLEVECTOR_UFILEELEMENT_H
#define MUSCKLEVECTOR_UFILEELEMENT_H
#include <string>
#include <istream>
#include <vector>

class UfileElement {
private:
    std::vector<std::string> elemets;
public:
    explicit UfileElement(const std::string&, char delimeter=' ');
    UfileElement(UfileElement &ufileElement);
    UfileElement &operator=(const UfileElement &ufileElement);
    bool operator==(UfileElement &ufileElement);
    std::string getSUbElement(int index);
    friend std::ostream& operator<<(std::ostream &out, const UfileElement &ufileElement);
};
std::vector<std::string> getEl(const std::string &string, char delimiter);


#endif //MUSCKLEVECTOR_UFILEELEMENT_H
