/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *le_title;
    QTextEdit *le_description;
    QDateTimeEdit *dte_datetime;
    QToolButton *toolButton;

    void setupUi(QWidget *task)
    {
        if (task->objectName().isEmpty())
            task->setObjectName("task");
        task->resize(356, 215);
        task->setMaximumSize(QSize(356, 215));
        verticalLayout = new QVBoxLayout(task);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        le_title = new QLineEdit(task);
        le_title->setObjectName("le_title");
        le_title->setReadOnly(false);

        verticalLayout->addWidget(le_title);

        le_description = new QTextEdit(task);
        le_description->setObjectName("le_description");
        le_description->setReadOnly(false);

        verticalLayout->addWidget(le_description);

        dte_datetime = new QDateTimeEdit(task);
        dte_datetime->setObjectName("dte_datetime");
        dte_datetime->setReadOnly(false);

        verticalLayout->addWidget(dte_datetime);

        toolButton = new QToolButton(task);
        toolButton->setObjectName("toolButton");

        verticalLayout->addWidget(toolButton);


        retranslateUi(task);

        QMetaObject::connectSlotsByName(task);
    } // setupUi

    void retranslateUi(QWidget *task)
    {
        task->setWindowTitle(QCoreApplication::translate("task", "Form", nullptr));
        le_title->setText(QCoreApplication::translate("task", "huesos", nullptr));
        le_description->setHtml(QCoreApplication::translate("task", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">description</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        toolButton->setText(QCoreApplication::translate("task", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task: public Ui_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
