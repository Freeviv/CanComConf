#include "qtreemessageitem.h"

// TODO: segsev after closing

QTreeMessageItem::QTreeMessageItem(QTreeWidget *parent)
    : QTreeWidgetItem(parent)
{
    m_parent = parent;
    m_type_self = Undefined;
    m_type_children = Undefined;
}

QTreeMessageItem::QTreeMessageItem(QTreeMessageItem *parent)
    : QTreeWidgetItem(parent)
{
    m_parent = parent;
    m_type_self = Undefined;
    m_type_children = Undefined;
}

QTreeMessageItem::QTreeMessageItem(QTreeMessageItem *parent, const QStringList &strings)
    : QTreeWidgetItem(parent,strings)
{
    m_parent = parent;
    m_type_self = Undefined;
    m_type_children = Undefined;
}

bool QTreeMessageItem::applyItemInfo(ItemInformation info, QString name)
{
    m_type_self = (info.group_info) ? Group : Item;
    if(m_type_self == Group)
    {
        m_info = new QTreeMessageItem(this,QStringList("Information"));

        // TODO insert information here
        QString str;
        QTreeWidgetItem *item = new QTreeWidgetItem(m_info);
        item->setText(0,str.sprintf("%-30s %s","Identifier Type",(info.id_type == STANDARD) ? "STANDARD" : "EXTENDED"));
        m_info->addChild(item);

        item = new QTreeWidgetItem(m_info);
        item->setText(0,str.sprintf("%-30s %s","Don't cares",(info.id_type == STANDARD) ? "STANDARD" : "EXTENDED"));
        m_info->addChild(item);


        m_children = new QTreeMessageItem(this);
        m_children->setText(0,tr("Children"));
        addChild(m_children);
    }
    this->setText(0,name);
    this->setBackground(0,QBrush(Qt::lightGray));

    return false;
}

bool QTreeMessageItem::addMessageItem(ItemInformation info, QString name)
{
    QTreeMessageItem *item = new QTreeMessageItem(m_children);
    item->applyItemInfo(info,name);
    //this->removeChild(item);
    m_children->addChild(item);
    return true;
}

TreeItemType QTreeMessageItem::getType() const
{
    return m_type_self;
}

QObject * QTreeMessageItem::getParent() const
{
    return m_parent;
}

QByteArray QTreeMessageItem::getData() const
{
    QByteArray data;
    if(m_children != nullptr)
    {
        for(int i = 0; i < m_children->childCount(); ++i)
        {
            QTreeMessageItem *item = dynamic_cast<QTreeMessageItem*>(m_children->child(i));
            if(item != NULL)
            {
                data += item->getData();
            }
        }
    }
    // TODO fill m_info_struct with correct data
    QByteArray info((const char*)&m_info_struct,sizeof(ItemInformation));
    info.append(m_name);
    return info + data;
}
