#include "entryedit.h"
#include "ui_entryedit.h"

EntryEdit::EntryEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryEdit)
{
    ui->setupUi(this);
    ui->lineEdit_mask->allowDontCares(false);
}

EntryEdit::~EntryEdit()
{
    delete ui;
}

void EntryEdit::on_lineEdit_mask_cursorPositionChanged(int prev, int cur)
{
    (void)prev;
    ui->label_cursorPosValue->setText(QString::number(cur));
}
