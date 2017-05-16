#ifndef MYIS_EDITOR_H
#define MYIS_EDITOR_H

#include <QMainWindow>
#include <QTextCursor>
#include <QTextBlockFormat>
#include <time.h>
#include "lex_analyzer.h"
#include "language_server_communicator.h"

namespace Ui {
class myis_editor;
}

class myis_editor : public QMainWindow {
    Q_OBJECT
public:
    explicit myis_editor(QWidget *parent = 0);
    ~myis_editor();


private slots:
    void on_textEdit_textChanged();
    void on_textEdit_cursorPositionChanged();

    void on_actionSyntax_Tree_Viewer_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionRecursive_triggered();

    void on_actionLL1_triggered();

    void on_actionLR1_triggered();

    void on_actionCompile_triggered();

private:
    lex_analyzer *analyzer;
    language_server_communicator *lserver;
    Ui::myis_editor *ui;
    int newLine;
    int programEdit;
    int lastLineNum;
    QString filePath;
    QString folderPath;
    QString snlPath;
    time_t lastEditTime;
    int edit;
    QString nowCompiler;
    void highlightLineText(int);
    void saveTo(QString);
    void loadFile(QString);
    void setRed(int);
    QString getWholeText();
    int getCurrentLineNumber();
    QString getLine(int);
    void delLine(int);
    void delAll();
    void insertHtml(int, QString &);
    //QString &parseTokenToHtml(QString &);
    void parseByLanguageServer(QString);
};

#endif // MYIS_EDITOR_H
