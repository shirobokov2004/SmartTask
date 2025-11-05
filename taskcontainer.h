#ifndef TASKCONTAINER_H
#define TASKCONTAINER_H

#include <QObject>
#include <QWidget>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QLabel>
#include <QSpacerItem>
#include <task.h>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QAction>
#include <QMenu>

class QPropertyAnimation;

class TaskContainer : public QWidget
{
    Q_OBJECT
public:
    explicit TaskContainer(QString title, QWidget *parent = nullptr);
    void addTask(Task* task, int index = -1);
    void createTask();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private:
    int insertionIndexForPos(const QPoint &pos);
    void updateIndicator();
    void showContextMenu(const QPoint &pos);

    QSpacerItem *spacer;
    QVBoxLayout *layout;
    int m_insertIndex = -1;
    QWidget *m_indicator;
};

#endif // TASKCONTAINER_H
