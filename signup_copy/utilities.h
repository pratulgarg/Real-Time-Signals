    #ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include "utilities.h"


//class utilities
//{
//public:
//    utilities();

//};
//QString hashPassword(const QString &password);
class Utilities {
public:
    static QString hashPassword(const QString& password);
};


#endif // UTILITIES_H
