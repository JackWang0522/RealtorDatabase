//
// Created by Jack's Matebook on 6/3/2017.
//

#ifndef FINAL_PROJECT_HOUSE_H
#define FINAL_PROJECT_HOUSE_H

#include <iostream>

class House{
public:
    House();
    ~House();
    std::string getAddress() const;
    std::string getMLS() const;
    void display() const;
    void create();

private:
    std::string _streetAddress;
    std::string _city;
    std::string _state;
    std::string _zipCode;
    std::string _MLS;
    int _sellingPrice;
    int _bedroomCount;
    int _bathroomCount;
    int _storiesCount;
    int _livingAreaSQFT;
    int _landAreaSQFT;
};

#endif //FINAL_PROJECT_HOUSE_H
