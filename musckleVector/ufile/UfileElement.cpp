//
// Created by dmitriy on 28.10.2021.
//

#include "UfileElement.h"


UfileElement::UfileElement(const std::string& string, char delimeter) {
    this->elemets = getEl(string, delimeter);
}

UfileElement::UfileElement(UfileElement &ufileElement) {
    this->elemets = ufileElement.elemets;
}

UfileElement &UfileElement::operator=(const UfileElement &ufileElement) = default;

bool UfileElement::operator==(UfileElement &ufileElement) {
    if(this->elemets.size() != ufileElement.elemets.size()){
        return false;
    }
    for(int i = 0; i < this->elemets.size(); i++){
        if(this->elemets[i] != ufileElement.elemets[i]){
            return false;
        }
    }
    return true;
}

std::string UfileElement::getSUbElement(int index) {
    if(index >= this->elemets.size()){
        throw std::exception();
    }
    return this->elemets[index];
}

std::ostream &operator<<(std::ostream &out, const UfileElement &ufileElement){
    for(auto &item: ufileElement.elemets){
        out << item << " ";
    }
    return out;
}


std::vector<std::string> getEl(const std::string &string, char delimiter){
    std::vector<std::string> ans;
    std::string buff;
    for(auto &symbol : string){
        if(symbol == delimiter){
            ans.push_back(buff);
            buff = "";
        }else{
            buff += symbol;
        }
    }
    return ans;
}