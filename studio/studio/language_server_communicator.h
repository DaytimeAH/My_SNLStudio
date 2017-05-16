#ifndef LANGUAGE_SERVER_COMMUNICATOR_H
#define LANGUAGE_SERVER_COMMUNICATOR_H

#include <cstddef>
#include <QString>

class language_server_communicator {
public:
    language_server_communicator();
    int sendToParse(QString &path, QChar selection);
    int waitForResponse(int = 10);
    QString getHtml();
private:
    size_t getResponse(char* buffer, size_t bufferSize);

};

#endif // LANGUAGE_SERVER_COMMUNICATOR_H
