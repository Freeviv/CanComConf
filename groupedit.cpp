#include "groupedit.h"
#include "ui_groupedit.h"

#include <QDebug>
#include <QString>

#include <cmath>

GroupEdit::GroupEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupEdit)
{
    ui->setupUi(this);
    ui->lineEdit_mask->setMaxLength(STANDARD);
    idType = STANDARD;
    ui->label_wrongMaskInput->hide();
    ui->lineEdit_mask->setEnabled(false);
}

GroupEdit::~GroupEdit()
{
    delete ui;
}

void GroupEdit::on_radioButton_si_clicked()
{
    ui->lineEdit_mask->setMaxLength(STANDARD);
    idType = STANDARD;
}

void GroupEdit::on_radioButton_ei_clicked()
{
    ui->lineEdit_mask->setMaxLength(EXTENDED);
    idType = EXTENDED;
}

void GroupEdit::on_checkBox_maskEnable_stateChanged(int arg1)
{
    qDebug() << arg1;
    if(arg1)
    {
        // checked
        ui->lineEdit_mask->setEnabled(true);
    }
    else
    {
        // not checked
        ui->lineEdit_mask->setEnabled(false);
    }
}

void GroupEdit::on_lineEdit_mask_cursorPositionChanged(int prev, int cur)
{
    (void)prev;
    ui->label_CursorPosNr->setText(QString::number(cur));
}

void GroupEdit::on_lineEdit_mask_textEdited(const QString &arg1)
{
    // calcs messages available in the mask
    int dontCares = (arg1.count(QLatin1Char('x')) + arg1.count(QLatin1Char('X'))) - 1;
    uint64_t n_messages = (dontCares >= 0) ? 2 << dontCares : 0;
    ui->label_messagesAvailable->setText(QString::number(n_messages));
}


