#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    QFile styleFile(":/style.qss");
    if(styleFile.open(QFile::ReadOnly | QFile::Text)){
        QTextStream stream(&styleFile);
        QString style = stream.readAll();
        a.setStyleSheet(style);
        qWarning() << "Load styles(" ;
        styleFile.close();
    }else{
        qWarning() << "Can`t load styles(" ;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
