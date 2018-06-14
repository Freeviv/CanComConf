#ifndef MESSAGETREEENTRY_H
#define MESSAGETREEENTRY_H

#include <QByteArray>

class MessageTreeEntry
{
public:
    virtual QByteArray getRawData() = 0;
    virtual ~MessageTreeEntry(){}
};

#endif // MESSAGETREEENTRY_H
