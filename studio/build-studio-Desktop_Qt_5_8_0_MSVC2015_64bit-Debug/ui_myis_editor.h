/********************************************************************************
** Form generated from reading UI file 'myis_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYIS_EDITOR_H
#define UI_MYIS_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myis_editor
{
public:
    QAction *actionCompile;
    QAction *actionRecursive;
    QAction *actionLL1;
    QAction *actionLR1;
    QAction *actionSyntax_Tree_Viewer;
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuRun;
    QMenu *menuCompiler;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myis_editor)
    {
        if (myis_editor->objectName().isEmpty())
            myis_editor->setObjectName(QStringLiteral("myis_editor"));
        myis_editor->resize(819, 581);
        actionCompile = new QAction(myis_editor);
        actionCompile->setObjectName(QStringLiteral("actionCompile"));
        actionRecursive = new QAction(myis_editor);
        actionRecursive->setObjectName(QStringLiteral("actionRecursive"));
        actionLL1 = new QAction(myis_editor);
        actionLL1->setObjectName(QStringLiteral("actionLL1"));
        actionLR1 = new QAction(myis_editor);
        actionLR1->setObjectName(QStringLiteral("actionLR1"));
        actionSyntax_Tree_Viewer = new QAction(myis_editor);
        actionSyntax_Tree_Viewer->setObjectName(QStringLiteral("actionSyntax_Tree_Viewer"));
        actionOpen = new QAction(myis_editor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(myis_editor);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(myis_editor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro"));
        font.setPointSize(18);
        textEdit->setFont(font);
        textEdit->setAutoFillBackground(true);
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(0, 43, 54);\n"
"selection-color: rgb(101, 123, 131);\n"
"selection-background-color: rgb(253, 246, 227);"));
        textEdit->setMidLineWidth(-3);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout_2->addWidget(textEdit);

        myis_editor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(myis_editor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 26));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        menuCompiler = new QMenu(menuBar);
        menuCompiler->setObjectName(QStringLiteral("menuCompiler"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        myis_editor->setMenuBar(menuBar);
        statusBar = new QStatusBar(myis_editor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myis_editor->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuCompiler->menuAction());
        menuRun->addAction(actionCompile);
        menuRun->addAction(actionSyntax_Tree_Viewer);
        menuCompiler->addAction(actionRecursive);
        menuCompiler->addAction(actionLL1);
        menuCompiler->addAction(actionLR1);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(myis_editor);

        QMetaObject::connectSlotsByName(myis_editor);
    } // setupUi

    void retranslateUi(QMainWindow *myis_editor)
    {
        myis_editor->setWindowTitle(QApplication::translate("myis_editor", "myis_editor", Q_NULLPTR));
        actionCompile->setText(QApplication::translate("myis_editor", "Generate Syntax Tree", Q_NULLPTR));
        actionRecursive->setText(QApplication::translate("myis_editor", "Recursive", Q_NULLPTR));
        actionLL1->setText(QApplication::translate("myis_editor", "LL1", Q_NULLPTR));
        actionLR1->setText(QApplication::translate("myis_editor", "LR1", Q_NULLPTR));
        actionSyntax_Tree_Viewer->setText(QApplication::translate("myis_editor", "Syntax Tree Viewer", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("myis_editor", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("myis_editor", "Save", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("myis_editor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Source Code Pro'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.SF NS Text'; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        menuRun->setTitle(QApplication::translate("myis_editor", "Run", Q_NULLPTR));
        menuCompiler->setTitle(QApplication::translate("myis_editor", "Compiler", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("myis_editor", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class myis_editor: public Ui_myis_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIS_EDITOR_H
