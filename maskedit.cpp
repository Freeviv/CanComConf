#include "maskedit.h"

#include <QKeyEvent>

MaskEdit::MaskEdit(QWidget *parent)
    : QLineEdit(parent)
{
    m_dontCaresAllowed = true;
}

void MaskEdit::allowDontCares(bool allow)
{
    m_dontCaresAllowed = allow;
}

void MaskEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_0 ||
       event->key() == Qt::Key_1 ||
       (event->key() == Qt::Key_X && m_dontCaresAllowed) ||
       event->key() == Qt::Key_Delete ||
       event->key() == Qt::Key_Backspace ||
       event->key() == Qt::Key_Left ||
       event->key() == Qt::Key_Right)
    {
        QLineEdit::keyPressEvent(event);
    }
}
