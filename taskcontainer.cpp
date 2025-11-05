#include "taskcontainer.h"

TaskContainer::TaskContainer(QString title, QWidget *parent)
    : QWidget{parent}
{
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::CustomContextMenu);

    QLabel *l_title = new QLabel(title);
    m_indicator = new QWidget(this);
    spacer = new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout = new QVBoxLayout(this);
    layout->addWidget(l_title);
    layout->addStretch();
    this->setLayout(layout);

    connect(this, QWidget::customContextMenuRequested, this, TaskContainer::showContextMenu);
}

void TaskContainer::addTask(Task *task, int index)
{
    if(index == -1)
    {
        layout->insertWidget(layout->count() - 1, task);
    } else {
        layout->insertWidget(index, task);
    }
}

void TaskContainer::createTask()
{
    Task *task = new Task(this);
    addTask(task, -1);
}


void TaskContainer::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("title")){
        event->acceptProposedAction();
    }
}

void TaskContainer::dragMoveEvent(QDragMoveEvent *event)
{
    int index = insertionIndexForPos(event->pos());

    if(index != m_insertIndex){
        m_insertIndex = index;
        updateIndicator();
    }
    event->acceptProposedAction();
}

void TaskContainer::dragLeaveEvent(QDragLeaveEvent *event)
{
    m_indicator->hide();
    m_insertIndex = -1;
}

void TaskContainer::dropEvent(QDropEvent *event)
{
    const QMimeData *mime = event->mimeData();

    if(mime->hasFormat("title")){
        QString title = mime->data("title");
        QString description = mime->data("description");
        QDateTime deadline = QDateTime::fromString(mime->data("deadline"), "dd.MM.yyyy hh:mm:ss");

        Task *task = new Task(title, description, deadline, this);

        QPoint dropPos = event->pos();
        int index = insertionIndexForPos(dropPos);

        addTask(task, index);
    }
    m_indicator->hide();
    m_insertIndex = -1;

    event->acceptProposedAction();
}

int TaskContainer::insertionIndexForPos(const QPoint &pos)
{
    for (int i = 0; i < layout->count() - 1; ++i) {  // -1: пропускаем stretch
        QLayoutItem *item = layout->itemAt(i);
        if (!item || !item->widget()) continue;

        QWidget *widget = item->widget();
        QRect rect = widget->geometry();

        // Если курсор в верхней половине виджета — вставляем ПЕРЕД ним
        if (rect.top() <= pos.y() && pos.y() <= rect.center().y()) {
            return i;
        }
        // Если в нижней половине — вставляем ПОСЛЕ него
        else if (rect.center().y() < pos.y() && pos.y() <= rect.bottom()) {
            return i + 1;
        }
    }

    // Если ниже всех — в конец
    return layout->count() - 1;
}

void TaskContainer::updateIndicator()
{
    if (m_insertIndex == -1 || m_insertIndex >= layout->count() - 1) {
        m_indicator->hide();
        return;
    }

    QLayoutItem *item = layout->itemAt(m_insertIndex);
    if (item && item->widget()) {
        QRect r = item->widget()->geometry();
        m_indicator->setGeometry(0, r.top(), width(), 2);
    } else {
        // Вставка в конец — под последним виджетом
        int last = layout->count() - 2;
        if (last >= 0) {
            QRect r = layout->itemAt(last)->widget()->geometry();
            m_indicator->setGeometry(0, r.bottom() + 1, width(), 2);
        }
    }
    m_indicator->setStyleSheet("border: 1px solid #F3A505");
    m_indicator->show();
    m_indicator->raise();
}

void TaskContainer::showContextMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);
    QAction *createTask = new QAction("Create task", this);
    connect(createTask, &QAction::triggered, this, &TaskContainer::createTask);
    menu->addAction(createTask);
    menu->popup(mapToGlobal(pos));
}
