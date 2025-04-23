#include "utilities.h"
#include <QCryptographicHash>


QString Utilities::hashPassword(const QString& password) {
    if (password.isEmpty()) {
        // Handle empty password case
        return "";
    }
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}
