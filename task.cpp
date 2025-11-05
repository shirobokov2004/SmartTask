#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task)
{
    ui->setupUi(this);
    connect(ui->toolButton, &QToolButton::clicked, this, &Task::deleteLater);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, QWidget::customContextMenuRequested, this, &Task::showContextMenu);
}


Task::Task(QString title, QString description, QDateTime deadline, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task)
{
    ui->setupUi(this);
    connect(ui->toolButton, &QToolButton::clicked, this, &Task::deleteLater);
    ui->le_title->setText(title);
    ui->le_description->setText(description);
    ui->dte_datetime->setDateTime(deadline);
}

Task::~Task()
{
    delete ui;
}

void Task::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_startPos = event->pos();
    }
}

void Task::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons() & Qt::LeftButton))
        return;

    if((event->pos() - m_startPos).manhattanLength() < QApplication::startDragDistance())
        return;

    auto *drag = new QDrag(this);

    auto *mime = new QMimeData;
    mime->setData("title", ui->le_title->text().toUtf8());
    mime->setData("description", ui->le_description->toPlainText().toUtf8());
    mime->setData("deadline", ui->dte_datetime->dateTime().toString("dd.MM.yyyy hh:mm:ss").toUtf8());
    drag->setMimeData(mime);

    qDebug() << mime->data("deadline");

    QPixmap pixmap(size());
    render(&pixmap);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - rect().topLeft());


    Qt::DropAction result = drag->exec();
    if(result = Qt::MoveAction)
        hide();
}

void Task::showContextMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);
    QAction *deleteTask = new QAction("Delete task", this);
    connect(deleteTask, &QAction::triggered, this, &Task::deleteLater);
    menu->addAction(deleteTask);
    menu->popup(mapToGlobal(pos));
}
