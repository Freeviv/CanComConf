#ifndef MESSAGEGROUP_H
#define MESSAGEGROUP_H

#include <vector>
#include <stddef.h>
#include <map>

#include <QString>

#include "messagetreeentry.h"
#include "messageentry.h"
#include "structs.h"

enum GroupType
{
    Group,
    Entries,
    Undefined
};


class MessageEntry;

class MessageGroup : public MessageTreeEntry
{
public:
    MessageGroup(QString name, MessageGroup *parent = nullptr, GroupInformation *info = nullptr);
    ~MessageGroup();
    bool addMessageGroup(GroupInformation info, QString name);
    bool addMessageEntry(MessageInformation info, QString name);
    QByteArray getRawData();

private:
    bool m_isRoot;
    GroupType m_gType;
    std::map<int64_t,MessageTreeEntry*> m_entries;
    QString m_name;
    GroupInformation m_gInfo;


    void applyGroupInfo(GroupInformation *info, QString name);

};

#endif // MESSAGEGROUP_H
