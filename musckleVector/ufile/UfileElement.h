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
    UfileElement();

    explicit UfileElement(const std::string&, char delimeter='\t');
    UfileElement(const UfileElement &ufileElement);
    UfileElement &operator=(const UfileElement &ufileElement);
    bool operator==(UfileElement &ufileElement);
    std::string &operator[](unsigned long index) const;
    [[nodiscard]] unsigned long getSize() const;
    friend std::ostream& operator<<(std::ostream &out, const UfileElement &ufileElement);
};
std::vector<std::string> getEl(const std::string &string, char delimiter);


#endif //MUSCKLEVECTOR_UFILEELEMENT_H
