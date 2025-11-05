#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <taskcontainer.h>
#include <QDrag>
#include <QMimeData>
#include <QHBoxLayout>
#include <task.h>


namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void addTask(Task *task);

private:
    TaskContainer *cont1;
    TaskContainer *cont2;
    TaskContainer *cont3;
};

#endif // BOARD_H
