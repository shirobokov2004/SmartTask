#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QVBoxLayout>
#include <task.h>
#include <board.h>
#include <boardbutton.h>
#include <boardhashmap.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createBoard();
    void openBoard();

private:
    void showContextMenu(const QPoint &pos);


    QSharedPointer<Board> activeBoard;
    BoardButton *activeButton;
    QVBoxLayout *buttonBoardContainerLayout;
    BoardHashMap boardStorage;
    int boardCounter = 1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
