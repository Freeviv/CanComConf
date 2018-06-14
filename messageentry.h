#ifndef MESSAGEENTRY_H
#define MESSAGEENTRY_H

#include "structs.h"
#include "messagegroup.h"
#include "messagetreeentry.h"

#include <QString>

class MessageGroup;

class MessageEntry : public MessageTreeEntry
{
public:
    MessageEntry(QString name, MessageGroup *parent, MessageInformation *info);
    QByteArray getRawData();

private:
    QString m_name;
    MessageInformation *m_mInfo;
    MessageGroup *m_parent;
};

#endif // MESSAGEENTRY_H
