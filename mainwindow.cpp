#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //init varibles
    ui->setupUi(this);
    activeBoard = QSharedPointer<Board>(new Board(this));
    buttonBoardContainerLayout = new QVBoxLayout();
    ui->boardButtonsContainer->setLayout(buttonBoardContainerLayout);
    activeButton = new BoardButton("You first board!", activeBoard);

    boardStorage.insert(activeButton->text(), activeBoard);
    activeButton->setEnabled(false);
    ui->boardButtonsContainer->setContextMenuPolicy(Qt::CustomContextMenu);
    buttonBoardContainerLayout->addWidget(activeButton);
    buttonBoardContainerLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));
    ui->centralwidget->layout()->addWidget(activeBoard.data());

    connect(activeButton, &BoardButton::clicked, this, &MainWindow::openBoard);
    connect(ui->boardButtonsContainer, &QWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createBoard()
{

    BoardButton *boardButton = new BoardButton("New Board " + QString::number(boardCounter++), QSharedPointer<Board>(new Board()));
    boardStorage.insert(boardButton->text(), boardButton->takeBoard());
    buttonBoardContainerLayout->insertWidget(buttonBoardContainerLayout->count() - 1, boardButton);
    connect(boardButton, &BoardButton::clicked, this, &MainWindow::openBoard);
}

void MainWindow::openBoard()
{
    activeBoard.data()->hide();
    activeButton->setEnabled(true);
    activeButton = qobject_cast<BoardButton*>(sender());
    activeButton->setEnabled(false);
    QString key = activeButton->text();
    activeBoard = boardStorage.value(key);
    ui->centralwidget->layout()->addWidget(activeBoard.data());
    if(activeBoard.data()->isHidden())
        activeBoard.data()->show();
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);
    QAction *createBoard = new QAction("Create board", this);
    connect(createBoard, &QAction::triggered, this, &MainWindow::createBoard);
    menu->addAction(createBoard);
    menu->popup(mapToGlobal(pos));
}
