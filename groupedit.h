#ifndef GROUPEDIT_H
#define GROUPEDIT_H

#include <QDialog>

#include "structs.h"


namespace Ui {
class GroupEdit;
}

class GroupEdit : public QDialog
{
    Q_OBJECT

public:
    explicit GroupEdit(QWidget *parent = 0);
    ~GroupEdit();

private slots:
    void on_radioButton_si_clicked();
    void on_radioButton_ei_clicked();
    void on_checkBox_maskEnable_stateChanged(int arg1);
    void on_lineEdit_mask_cursorPositionChanged(int prev, int cur);
    void on_lineEdit_mask_textEdited(const QString &arg1);

private:
    Ui::GroupEdit *ui;
    IdentifierType idType;
};

#endif // GROUPEDIT_H
