//
// Created by Jack on 6/10/2017.
//

#include <iostream>
#include "houseWithPool.h"

using namespace std;

// default constructor
HouseWithPool::HouseWithPool(int poolSize) : House(), _poolSize(poolSize), _poolDepth(0), _poolMaintenanceCost(0){}

int HouseWithPool::getPoolSize() { return _poolSize;}

int HouseWithPool::getPoolDepth() { return _poolDepth;}

int HouseWithPool::getPoolMaintenaceCost() { return _poolMaintenanceCost;}

void HouseWithPool::setPoolDepth(int poolDepth){_poolDepth = poolDepth;}

void HouseWithPool::setPoolSize(int poolSize) {_poolSize = poolSize;}

void HouseWithPool::setPoolMaintenaceCost(int poolMaintenanceCost) {_poolMaintenanceCost = poolMaintenanceCost;}

void HouseWithPool::displayHouseWithPool() const {
    display();
    cout << "Pool Size : " << _poolSize << "sqft\n"
            "Pool Depth : " << _poolDepth << "ft\n"
            "Pool Maintenance Cost : $" << _poolMaintenanceCost << "\n";
}