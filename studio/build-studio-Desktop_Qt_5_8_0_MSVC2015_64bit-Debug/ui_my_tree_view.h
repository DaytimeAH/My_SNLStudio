/********************************************************************************
** Form generated from reading UI file 'my_tree_view.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_TREE_VIEW_H
#define UI_MY_TREE_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_tree_view
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *my_tree_view)
    {
        if (my_tree_view->objectName().isEmpty())
            my_tree_view->setObjectName(QStringLiteral("my_tree_view"));
        my_tree_view->resize(800, 600);
        menubar = new QMenuBar(my_tree_view);
        menubar->setObjectName(QStringLiteral("menubar"));
        my_tree_view->setMenuBar(menubar);
        centralwidget = new QWidget(my_tree_view);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        my_tree_view->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(my_tree_view);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        my_tree_view->setStatusBar(statusbar);

        retranslateUi(my_tree_view);

        QMetaObject::connectSlotsByName(my_tree_view);
    } // setupUi

    void retranslateUi(QMainWindow *my_tree_view)
    {
        my_tree_view->setWindowTitle(QApplication::translate("my_tree_view", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class my_tree_view: public Ui_my_tree_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_TREE_VIEW_H
