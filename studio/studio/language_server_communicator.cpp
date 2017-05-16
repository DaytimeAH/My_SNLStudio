#include "language_server_communicator.h"

language_server_communicator::language_server_communicator() {

}

int language_server_communicator::sendToParse(QString &path, QChar selection) {
    /*QString callStr(selection);
    callStr = snlccPath + callStr + path + path;
    system(callStr.toLatin1());*/
    return 233;
}

int language_server_communicator::waitForResponse(int timeout){
    return 233;
}

QString language_server_communicator::getHtml() {
    return "233";
}
