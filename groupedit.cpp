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
    ui->spinBox_priority->setEnabled(false);
}

GroupEdit::~GroupEdit()
{
    delete ui;
}

GroupInformation GroupEdit::getResult()
{
    GroupInformation info;
    info.id_type = idType;
    QString mask_raw = ui->lineEdit_mask->text();
    bool ok;
    QString dontCares = mask_raw.replace('1','0');
    QString mask = mask_raw.replace('x','0');
    info.dontCares = dontCares.toInt(&ok,2);
    if(!ok)
        qWarning("Error while converting dont-care mask");
    info.mask = mask.toInt(&ok,2);
    if(!ok)
        qWarning("Error while converting mask");
    info.nameSize = 0;

    return info;
}

QString GroupEdit::getName()
{
    return ui->lineEdit_name->text();
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

void GroupEdit::on_radioButton_maskEnable_clicked()
{
    ui->lineEdit_mask->setEnabled(true);
    ui->spinBox_priority->setEnabled(false);
}

void GroupEdit::on_radioButton_priority_clicked()
{
    ui->spinBox_priority->setEnabled(true);
    ui->lineEdit_mask->setEnabled(false);
}
