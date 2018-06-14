#include "maskedit.h"

#include <QKeyEvent>

MaskEdit::MaskEdit(QWidget *parent)
    : QLineEdit(parent)
{}


void MaskEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_0 ||
       event->key() == Qt::Key_1 ||
       event->key() == Qt::Key_X ||
       event->key() == Qt::Key_Delete ||
       event->key() == Qt::Key_Backspace ||
       event->key() == Qt::Key_Left ||
       event->key() == Qt::Key_Right)
    {
        QLineEdit::keyPressEvent(event);
    }
}
