#include "entryedit.h"
#include "ui_entryedit.h"

EntryEdit::EntryEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryEdit)
{
    ui->setupUi(this);
}

EntryEdit::~EntryEdit()
{
    delete ui;
}
