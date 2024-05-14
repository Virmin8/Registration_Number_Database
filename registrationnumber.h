#ifndef REGISTRATIONNUMBER_H
#define REGISTRATIONNUMBER_H
#include <QString>
#include <QStringList>


class RegistrationNumber
{
public:
    RegistrationNumber();
    void addRegistrationNumber(QString number);
    QStringList getRegistrationNumber();
    void removeRegistrationNumber(QString remove);
    void replaceRegistrationNumber(QString number,QString Replace);


private:
    QStringList r_RegistrationNumber;

};

#endif // REGISTRATIONNUMBER_H
