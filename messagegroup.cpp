#include "messagegroup.h"

MessageGroup::MessageGroup(QString name,MessageGroup *parent, GroupInformation *info)
{
    m_isRoot = parent == nullptr;
    m_gType = Undefined;
    if(!m_isRoot)applyGroupInfo(info,name);
}

MessageGroup::~MessageGroup()
{
    if(m_gType != Undefined)
    {
        for(std::map<int64_t, MessageTreeEntry*>::iterator it=m_entries.begin();
            it != m_entries.end(); ++it)
        {
            delete it->second;
        }
    }
}

bool MessageGroup::addMessageGroup(GroupInformation info, QString name)
{
    // TODO check if prio does exists
    if(m_gType == Entries)
        return false;
    if(m_gType == Undefined)
        m_gType = Group;
    m_entries[info.priority] = (MessageGroup*)(new MessageGroup(name,this,&info));
    return true;
}

bool MessageGroup::addMessageEntry(MessageInformation info, QString name)
{
    // TODO check if prio does exists
    if(m_gType == Group)
        return false;
    if(m_gType == Undefined)
        m_gType = Entries;
    m_entries[info.priority] = (MessageEntry*)(new MessageEntry(name,this,&info));
    return true;
}

QByteArray MessageGroup::getRawData()
{
    QByteArray arr;
    for(std::map<int64_t, MessageTreeEntry*>::iterator it=m_entries.begin();
        it != m_entries.end(); ++it)
    {
        arr += it->second->getRawData();
    }
    m_gInfo.bytesToNext = m_name.size() + arr.size() + sizeof(GroupInformation);
    m_gInfo.nChildren = m_entries.size();
    arr.prepend(QByteArray::fromStdString(m_name.toStdString()));
    arr.prepend(QByteArray::fromRawData((const char*)&m_gInfo,sizeof(GroupInformation)));
    return arr;
}

void MessageGroup::applyGroupInfo(GroupInformation *info, QString name)
{
    m_name = name;
    memcpy(&m_gInfo,info,sizeof(GroupInformation));
}
