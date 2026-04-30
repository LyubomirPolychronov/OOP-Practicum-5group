#include "Computer_Peripheral.h"

double Computer_Peripheral::getPrice() const
{
    return price;
}

const std::string& Computer_Peripheral::getModel() const
{
    return model;
}

const std::string& Computer_Peripheral::getManufacturer() const
{
    return manufacturer;
}
