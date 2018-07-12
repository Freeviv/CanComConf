#include "groupedit.h"
#include "ui_groupedit.h"


#include <QDebug>
#include <QString>
#include <QMessageBox>

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

void GroupEdit::setAsEdit(ItemInformation info, QString name)
{
    ui->lineEdit_name->setText(name);
    switch(info.id_type)
    {
    case STANDARD:
        on_radioButton_si_clicked();
        break;
    case EXTENDED:
        on_radioButton_ei_clicked();
        break;
    default:
        qWarning("Unknown Identifier type!");
        break;
    }
    if(info.maskSet)
    {
        QString mask = QString::number(info.mask,2);
        QString dontCare = QString::number(info.dontCares,2);
        QString maskText;
        for(int i = 0; i < idType; ++i)
        {
            maskText += (dontCare.at(i) == '0') ? mask.at(i) : 'x';
        }
        ui->lineEdit_mask->setText(maskText);
    }
    else
    {
        ui->spinBox_priority->setValue(info.priority);
    }
}

ItemInformation GroupEdit::getResult()
{
    ItemInformation info;
    info.id_type = idType;
    if(ui->radioButton_maskEnable->isChecked())
    {
        bool ok;
        //TODO convert correctly
        QString dontCares(ui->lineEdit_mask->text());
        dontCares.replace('1','0').replace('x','1');
        QString mask(ui->lineEdit_mask->text());
        mask.replace('x','0');
        info.dontCares = dontCares.toInt(&ok,2);
        if(!ok)
            qWarning("Error while converting dont-care mask");
        info.mask = mask.toInt(&ok,2);
        if(!ok)
            qWarning("Error while converting mask");
        info.maskSet = true;
        qDebug() << dontCares;
        qDebug() << mask;
    }
    else
    {
        info.priority = ui->spinBox_priority->value();
        info.maskSet = false;
    }
    info.nameSize = 0;
    info.group_info = true;
    return info;
}

QString GroupEdit::getName()
{
    return ui->lineEdit_name->text();
}

void GroupEdit::on_radioButton_si_clicked()
{

    if(ui->lineEdit_mask->text().size() >= STANDARD)
    {
        int rv = QMessageBox::warning(this,tr("Discard Mask?"),tr("Your current mask is longer than 11 bits"),QMessageBox::Abort,QMessageBox::Ok);
        if(rv == QMessageBox::Abort)
        {
            ui->radioButton_ei->setChecked(true);
            ui->radioButton_si->setChecked(false);
            return;
        }
    }
    ui->lineEdit_mask->setMaxLength(STANDARD);
    idType = STANDARD;
}

void GroupEdit::on_radioButton_ei_clicked()
{
    ui->lineEdit_mask->setMaxLength(EXTENDED);
    idType = EXTENDED;
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
