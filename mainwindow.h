#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    void createToolbar();

private slots:
    void toolbar_addGroupPressed();
    void toolbar_removeGroupPressed();
    void toolbar_addEntryPressed();
    void toolbar_removeEntryPressed();
    void toolbar_elementMoveUpPressed();
    void toolbar_elementMoveDownPressed();
};

#endif // MAINWINDOW_H
