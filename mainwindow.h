#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QVBoxLayout>
#include <task.h>
#include <board.h>
#include <boardbutton.h>

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

private:
    void showContextMenu(const QPoint &pos);
    Board *activeBoard;
    QVBoxLayout *buttonBoardContainerLayout;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
