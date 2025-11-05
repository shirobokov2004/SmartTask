#ifndef BOARDBUTTON_H
#define BOARDBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <board.h>

class BoardButton : public QPushButton
{
    Q_OBJECT
public:
    BoardButton(QString nameBtn, Board *boardPtr);
private:
    QString name = "";
    Board *board;
};

#endif // BOARDBUTTON_H
