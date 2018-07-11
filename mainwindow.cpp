#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "groupedit.h"
#include "qtreemessageitem.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createToolbar();
    ui->groupEntries->setHeaderLabel(tr("Unknown Projekt"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    // clear selection on escape to allow adding new groups on root-level
    if(event->key() == Qt::Key_Escape)
    {
        ui->groupEntries->selectionModel()->clearSelection();
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::createToolbar()
{
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/add_group.svg"),   tr("Add Group"),   this,SLOT(toolbar_addGroupPressed()));
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/remove_group.svg"),tr("Remove Group"),this,SLOT(toolbar_removeGroupPressed()));
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/add_entry.svg"),   tr("Add Entry"),   this,SLOT(toolbar_addEntryPressed()));
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/remove_entry.svg"),tr("Remove Entry"),this,SLOT(toolbar_removeEntryPressed()));
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/element_up.svg"),  tr("Element up"),  this,SLOT(toolbar_elementMoveUpPressed()));
    ui->mainToolBar->addAction(QIcon(":/symbols/symbols/element_down.svg"),tr("Element down"),this,SLOT(toolbar_elementMoveDownPressed()));
}


void MainWindow::toolbar_addGroupPressed()
{
    GroupEdit edit;
    edit.setWindowTitle(tr("Add Group"));
    edit.exec();
    ItemInformation info = edit.getResult();
    QString name = edit.getName();

    if(ui->groupEntries->selectedItems().size() > 0)
    {
        // get one selected element and make it root for new element
        QTreeMessageItem *parent = dynamic_cast<QTreeMessageItem*>(ui->groupEntries->selectedItems().first());
        if(parent == NULL)
        {
            qDebug("dynamic_cast error 1");
            return;
        }
        // get the "root"-group-element of first selected item
        while(parent->getType() != Group)
        {
            parent = dynamic_cast<QTreeMessageItem*>(parent->getParent());
            if(parent == NULL)
            {
                qDebug("dynamic_cast error 2");
                return;
            }
        }
        parent->addMessageItem(info,name);
    }
    else
    {
        qDebug("New toplevel item");
        QTreeMessageItem *item = new QTreeMessageItem(ui->groupEntries);
        item->applyItemInfo(info,name);
        ui->groupEntries->addTopLevelItem(item);
    }

}

void MainWindow::toolbar_removeGroupPressed()
{
    qDebug("Remove Group");
}

void MainWindow::toolbar_addEntryPressed()
{
    qDebug("Add Entry");
}

void MainWindow::toolbar_removeEntryPressed()
{
    qDebug("Remove Entry");
}

void MainWindow::toolbar_elementMoveUpPressed()
{
    qDebug("Element move up");
}

void MainWindow::toolbar_elementMoveDownPressed()
{
    qDebug("Element move down");
}
