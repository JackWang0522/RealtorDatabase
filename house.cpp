//
// Created by Jack's Matebook on 6/3/2017.
//

#include <iostream>
#include "house.h"

using namespace std;

// default constructor
House::House() {
    _streetAddress = "";
    _city = "";
    _state = "";
    _zipCode = "";
    _sellingPrice = 0;
    _bedroomCount = 0;
    _bathroomCount = 0;
    _storiesCount = 0;
    _livingAreaSQFT = 0;
    _landAreaSQFT = 0;
}

void House::display() const {
    cout << "====== House ======\n"
            "Street Address : " << _streetAddress << "\n"
            "City : " << _city << "\n"
            "State : " << _state << "\n"
            "Zip Code : " << _zipCode << "\n"
            "Selling Price : $" << _sellingPrice << "\n"
            "Bedroom Count : " << _bedroomCount << "\n"
            "Bathroom Count : " << _bathroomCount << "\n"
            "Stories Count : " << _storiesCount << "\n"
            "Living Area : " << _livingAreaSQFT << " sqft\n"
            "Land Area : " << _landAreaSQFT << " sqft\n";
}

std::string House::getAddress() const {
    return _streetAddress;
}

std::string House::getMLS() const {
    return _MLS;
}

void House::create() {
    cout << "Creating new house >>>>>>>>>>>>>>>>>>\n"
            "Street Address : ";
    cin >> _streetAddress;
    cout << "City : ";
    cin >> _city;
    cout << "State : ";
    cin >> _state;
    cout << "Zip Code : ";
    cin >> _zipCode;
    cout << "MLS Number : ";
    cin >> _MLS;
    cout << "Selling Price : $";
    cin >> _sellingPrice;
    cout << "Bedroom Count : ";
    cin >> _bedroomCount;
    cout << "Bathroom Count : ";
    cin >> _bathroomCount;
    cout << "Stories Count : ";
    cin >> _storiesCount;
    cout << "Living Area(sqft) : ";
    cin >> _livingAreaSQFT;
    cout << "Land Area(sqft) : ";
    cin >> _landAreaSQFT;
    cout << "new house created\n";
}

House::~House() {
}