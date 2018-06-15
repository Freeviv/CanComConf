#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "groupedit.h"

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
    GroupInformation info = edit.getResult();
    QString name = edit.getName();
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->groupEntries);
    item->setText(0,name);
    item->setText(1,QString::number(info.priority));
    ui->groupEntries->addTopLevelItem(item);
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
