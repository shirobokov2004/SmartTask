#include "boardbutton.h"

BoardButton::BoardButton(QString nameBtn, Board *boardPtr)
{
    name = nameBtn;
    board = boardPtr;
    setText(name);
}
