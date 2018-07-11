#ifndef QTREEMESSAGEITEM_H
#define QTREEMESSAGEITEM_H

#include <QObject>
#include <QByteArray>
#include <QTreeWidgetItem>

#include "structs.h"

enum TreeItemType
{
    Group,
    Item,
    Other,
    Undefined
};

class QTreeMessageItem : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    QTreeMessageItem(QTreeWidget *parent);
    QTreeMessageItem(QTreeMessageItem *parent);
    QTreeMessageItem(QTreeMessageItem *parent, const QStringList &strings);
    bool applyItemInfo(ItemInformation info, QString name);
    bool addMessageItem(ItemInformation info, QString name);
    TreeItemType getType() const;
    QObject *getParent() const;
    QByteArray getData() const;

private:
    QObject *m_parent;
    TreeItemType m_type_self;
    TreeItemType m_type_children;
    ItemInformation m_info_struct;
    QString m_name;
    QTreeMessageItem *m_children = nullptr;
    QTreeMessageItem *m_info = nullptr;
};

#endif // QTREEMESSAGEITEM_H
