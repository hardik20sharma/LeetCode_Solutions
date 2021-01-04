class ParkingSystem
{
    int big, medium, small;
    
public:
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType)
    {
        if( (carType == 1 && !big) || (carType == 2 && !medium) || (carType == 3 && !small) )
            return false;
        
        if(carType == 1 && big)
            big--;
        else if(carType == 2 && medium)
            medium--;
        else
            small--;
        
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
