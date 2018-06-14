#include "messageentry.h"

MessageEntry::MessageEntry(QString name, MessageGroup *parent, MessageInformation *info)
{
    m_name = name;
    m_parent = parent;
    memcpy(&m_mInfo,info,sizeof(MessageInformation));
}

QByteArray MessageEntry::getRawData()
{
    QByteArray data = QByteArray::fromRawData((const char*)&m_mInfo,sizeof(MessageInformation));
    data.append(m_name);
    return data;
}
