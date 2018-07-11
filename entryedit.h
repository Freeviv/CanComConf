#ifndef ENTRYEDIT_H
#define ENTRYEDIT_H

#include <QDialog>

namespace Ui {
class EntryEdit;
}

class EntryEdit : public QDialog
{
    Q_OBJECT

public:
    explicit EntryEdit(QWidget *parent = 0);
    ~EntryEdit();

private slots:
    void on_lineEdit_mask_cursorPositionChanged(int prev, int cur);

private:
    Ui::EntryEdit *ui;
};

#endif // ENTRYEDIT_H
