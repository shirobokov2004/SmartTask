#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QDateTime>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QByteArray>
#include <QMenu>

namespace Ui {
class task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    explicit Task(QString title, QString description, QDateTime deadline,QWidget *parent = nullptr);
    ~Task();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void showContextMenu(const QPoint &pos);

    Ui::task *ui;
    QString title;
    QString description;
    int column;
    QDateTime deadline;

    QPoint m_startPos;
};

#endif // TASK_H
