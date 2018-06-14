#ifndef MASKEDIT_H
#define MASKEDIT_H

#include <QLineEdit>

class MaskEdit : public QLineEdit
{
    Q_OBJECT
public:
    MaskEdit(QWidget *parent);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MASKEDIT_H
