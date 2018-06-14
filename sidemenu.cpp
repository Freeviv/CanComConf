#include "sidemenu.h"
#include "ui_sidemenu.h"

SideMenu::SideMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideMenu)
{
    ui->setupUi(this);
}

SideMenu::~SideMenu()
{
    delete ui;
}
