#ifndef MASKEDIT_H
#define MASKEDIT_H

#include <QLineEdit>

class MaskEdit : public QLineEdit
{
    Q_OBJECT
public:
    MaskEdit(QWidget *parent);
    void allowDontCares(bool allow);

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    bool m_dontCaresAllowed;
};

#endif // MASKEDIT_H
