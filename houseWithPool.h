//
// Created by Jack on 6/10/2017.
//

#ifndef FINAL_PROJECT_HOUSEWITHPOOL_H
#define FINAL_PROJECT_HOUSEWITHPOOL_H

#include "house.h"

// Inherited class from House class, this class include pool information of the house.
class HouseWithPool : public House{
public:
    HouseWithPool(int poolSize);
    int getPoolSize();
    int getPoolDepth();
    int getPoolMaintenaceCost();
    void setPoolSize(int poolSize);
    void setPoolDepth(int poolDepth);
    void setPoolMaintenaceCost(int poolMaintenanceCost);
    void displayHouseWithPool() const ;

private:
    int _poolSize;
    int _poolDepth;
    int _poolMaintenanceCost;
};

#endif //FINAL_PROJECT_HOUSEWITHPOOL_H
