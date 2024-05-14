#include "registrationnumber.h"

RegistrationNumber::RegistrationNumber()
{

}

void RegistrationNumber::addRegistrationNumber(QString number)
{
    r_RegistrationNumber << number;
}

QStringList RegistrationNumber::getRegistrationNumber()
{
    return r_RegistrationNumber;
}

void RegistrationNumber::removeRegistrationNumber(QString remove)
 {
    for(int k = 0; k < r_RegistrationNumber.count(); k++)
        {
            if(r_RegistrationNumber[k] == remove)
            {
                r_RegistrationNumber.removeAt(k);
                break;
            }
        }

 }

void RegistrationNumber::replaceRegistrationNumber(QString number,QString Replace)
{
    for(int k = 0; k < r_RegistrationNumber.count(); k++)
        {
            if(r_RegistrationNumber[k] == number)
            {
                r_RegistrationNumber.replace(k,Replace);
                break;
            }
        }

}
