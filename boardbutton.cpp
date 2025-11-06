#include "boardbutton.h"

BoardButton::BoardButton(QString nameBtn, QSharedPointer<Board> boardPtr, QWidget *parent)
    :QPushButton(parent)
{
    name = nameBtn;
    board = boardPtr;
    setText(name);
}

QSharedPointer<Board> BoardButton::takeBoard()
{
    return board;
}
