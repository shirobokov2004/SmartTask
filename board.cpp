#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    // setAcceptDrops(true);
    cont1 = new TaskContainer("TODO",this);
    cont2 = new TaskContainer("PROCESS",this);
    cont3 = new TaskContainer("FINISED",this);
    this->setLayout(new QHBoxLayout(this));
    this->layout()->addWidget(cont1);
    this->layout()->addWidget(cont2);
    this->layout()->addWidget(cont3);
}

Board::~Board()
{
}

void Board::addTask(Task *task)
{
    cont1->addTask(new Task());
}


