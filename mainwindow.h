#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

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
    bool m_contentChanged;

    void createToolbar();

private slots:
    void contentEdited(bool changed);

    void treeWidget_doubleClickEvent(QTreeWidgetItem *item, int column);

    void toolbar_addGroupPressed();
    void toolbar_removeGroupPressed();
    void toolbar_addEntryPressed();
    void toolbar_removeEntryPressed();
    void toolbar_elementMoveUpPressed();
    void toolbar_elementMoveDownPressed();

    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
};

#endif // MAINWINDOW_H
