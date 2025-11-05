#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    activeBoard = new Board(this);
    buttonBoardContainerLayout = new QVBoxLayout();
    ui->boardButtonsContainer->setLayout(buttonBoardContainerLayout);
    BoardButton *boardBtn = new BoardButton("You first board!", activeBoard);
    ui->boardButtonsContainer->setContextMenuPolicy(Qt::CustomContextMenu);
    buttonBoardContainerLayout->addWidget(boardBtn);
    buttonBoardContainerLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));
    connect(ui->boardButtonsContainer, &QWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);

    ui->centralwidget->layout()->addWidget(activeBoard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createBoard()
{
    Board *board = new Board();
    BoardButton *boardButton = new BoardButton("New Board", board);
    buttonBoardContainerLayout->insertWidget(buttonBoardContainerLayout->count() - 1, boardButton);
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);
    QAction *createBoard = new QAction("Create board", this);
    connect(createBoard, &QAction::triggered, this, &MainWindow::createBoard);
    menu->addAction(createBoard);
    menu->popup(mapToGlobal(pos));
}
