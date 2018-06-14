#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>

namespace Ui {
class SideMenu;
}

class SideMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SideMenu(QWidget *parent = 0);
    ~SideMenu();

private:
    Ui::SideMenu *ui;
};

#endif // SIDEMENU_H
