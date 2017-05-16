#include "myis_editor.h"
#include "ui_myis_editor.h"
#include "my_tree_view.h"

#include <QTextFrame>
#include <QTextFrameFormat>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>

#include <iostream>
#include <queue>

const QString SNL_CONF = "C:\\Users\\DarknessH\\Desktop\\myIntelliStudio\\studio\\conf\\language\\SNL\\reg_expr.json";
const QString HL_CONF = "C:\\Users\\DarknessH\\Desktop\\myIntelliStudio\\studio\\conf\\highlight\\solarized_dark.json";

myis_editor::myis_editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myis_editor) {
        ui->setupUi(this);
        while(snlPath.isEmpty()) {
            snlPath =  QFileDialog::getOpenFileName(this, tr("Open SNL Compiler"), "../../", tr("Execuable(*.exe)"));
        }
        while(folderPath.isEmpty()) {
            folderPath = QFileDialog::getExistingDirectory(this,tr("Select Output Folder"),"../../");
        }
        lastLineNum = -100;
        edit = 0;
        filePath = "";
        programEdit = 0;
        newLine = 0;
        nowCompiler = "1";
        time(&lastEditTime);
        analyzer = new lex_analyzer(SNL_CONF, HL_CONF);
    }

myis_editor::~myis_editor() {
    delete ui;
}


void myis_editor::highlightLineText(int lineNumber) {
    QString str;
    str = getLine(lineNumber);
    if(str.isEmpty()) {
        return;
    }
    QString Str = analyzer->highlightStr(str);
    delLine(lineNumber);
    insertHtml(lineNumber, Str);
}

int myis_editor::getCurrentLineNumber() {
    QTextCursor cursor(ui -> textEdit -> textCursor());
    return cursor.blockNumber();
}

QString myis_editor::getLine(int lineNumber) {
    QTextDocument *textDocument = ui -> textEdit -> document();
    QTextBlock textBlock = textDocument -> findBlockByLineNumber(lineNumber);
    return textBlock.text();
}


void myis_editor::setRed(int lineNumber) {
    QTextCursor cursor(ui -> textEdit -> textCursor());
    int pos = ui -> textEdit->document()->findBlockByLineNumber(lineNumber).position();
    cursor.setPosition(pos);
    cursor.select(QTextCursor::LineUnderCursor);
    QTextCharFormat red;
    red.setUnderlineColor(QColor("red"));
    red.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
    cursor.setBlockCharFormat(red);
}

void myis_editor::delLine(int lineNumber){
    QTextCursor cursor(ui -> textEdit -> textCursor());
    int pos = ui -> textEdit->document()->findBlockByLineNumber(lineNumber).position();
    cursor.setPosition(pos);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.deleteChar();
}

void myis_editor::delAll() {
    programEdit = 1;
    QTextCursor cursor(ui -> textEdit -> textCursor());
    cursor.select(QTextCursor::Document);
    cursor.deleteChar();
    programEdit = 0;
}

void myis_editor::insertHtml(int lineNumber, QString &str){
    programEdit = 1;
    QTextCursor cursor(ui -> textEdit -> textCursor());
    int pos = ui -> textEdit->document()->findBlockByLineNumber(lineNumber).position();
    cursor.setPosition(pos);
    cursor.insertHtml(str);
    programEdit = 0;
}


void myis_editor::parseByLanguageServer(QString str){
    /*if(str.isEmpty()) {
        return;
    }
    lserver -> sendToParse(str);
    int lineNumber = lserver -> getErrorLineNumber();
    QTextCursor cursor(ui -> textEdit -> textCursor());
    int pos = cursor.position();
    setRed(lineNumber);
    cursor.setPosition(pos);
    ui -> textEdit -> setTextCursor(cursor);*/
}

void myis_editor::saveTo(QString filePath) {
    edit = 0;
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly|QFile::Text)) {
        QMessageBox::critical(this, "critical", "cannot write file");
    }
    else {
        QTextStream out(&file);
        out << ui -> textEdit->toPlainText();
    }
}

QString myis_editor::getWholeText() {
    programEdit = 1;
    QTextCursor cursor(ui -> textEdit -> textCursor());
    cursor.select(QTextCursor::Document);
    QString ret = cursor.selectedText();
    programEdit = 0;
    return ret;
}

void myis_editor::loadFile(QString str) {
    FILE *fp = fopen(str.toStdString().c_str(), "r");
    if(!fp) {
        QMessageBox::critical(this, "critical", "cannot read file");
        return;
    }
    delAll();
    char buffer[4096];
    while(fgets(buffer, 4095, fp)) {
        ui -> textEdit -> insertPlainText(buffer);
    }
}

//slots
void myis_editor::on_textEdit_textChanged() {
    if(!programEdit) {
        /*if(!filePath.isEmpty()) {
            time_t nowTime;
            time(&nowTime);
            double differTime = difftime(nowTime, lastEditTime);
            if(differTime > 3.0) {
                if(edit) {
                    saveTo(filePath);
                }
                parseByLanguageServer(filePath);
            }
            time(&lastEditTime);
        }*/
        QTextCursor cursor(ui -> textEdit -> textCursor());
        int pos = cursor.position();
        if(newLine) {
            int nowLine = getCurrentLineNumber();
            for(int i = 0; i <= nowLine; i++) {
                highlightLineText(i);
            }
        } else {
            highlightLineText(getCurrentLineNumber());
        }
        cursor.setPosition(pos);
        ui -> textEdit -> setTextCursor(cursor);
    }
}

void myis_editor::on_textEdit_cursorPositionChanged() {
    if(!programEdit) {
        programEdit = 1;
        QTextCursor cursor(ui -> textEdit ->textCursor());
        int lineNumber = cursor.blockNumber();
        if(lineNumber != lastLineNum) {
            newLine = 1;
            lastLineNum = lineNumber;
        } else {
            newLine = 0;
        }
        programEdit = 0;
    }
}

void myis_editor::on_actionSyntax_Tree_Viewer_triggered() {
    QWebEngineView *view = new QWebEngineView();
    view -> setUrl(QUrl("file:///C:/Users/DarknessH/Desktop/myIntelliStudio/studio/html/Json_show.html"));
    view ->show();
}

void myis_editor::on_actionSave_triggered() {
    if(!filePath.isEmpty()) {
        saveTo(filePath);
    } else {
        filePath = QFileDialog::getSaveFileName(this);
        if(!filePath.isEmpty())
            return saveTo(filePath);
    }
}

void myis_editor::on_actionOpen_triggered() {
    if(edit) {
        on_actionSave_triggered();
    }
    filePath = QFileDialog::getOpenFileName(this, tr("Open SNL File"), "../../", tr("SNL File(*.snl)"));
    if(!filePath.isEmpty()) {
        loadFile(filePath);
    }
}

void myis_editor::on_actionRecursive_triggered() {
    nowCompiler = "1";
}

void myis_editor::on_actionLL1_triggered() {
    nowCompiler = "2";
}

void myis_editor::on_actionLR1_triggered() {
    nowCompiler = "3";
}

void myis_editor::on_actionCompile_triggered() {
    on_actionSave_triggered();
    if(filePath.isEmpty()) {
        return;
    }
    QString cName;
    if(nowCompiler == "1") {
        cName = "recursive";
    } else if(nowCompiler == "2") {
        cName = "LL1";
    } else {
        cName = "LR1";
    }
    QString exec = snlPath\
                   + ' '\
                   + nowCompiler\
                   + ' '\
                   + filePath\
                   + ' '\
                   + folderPath\
                   + "/syntax_tree_"\
                   + cName\
                   + "ZZ.json > "\
                   + folderPath\
                   + "/log.txt";
    std::cout << exec.toStdString() << std::endl;
    system(exec.toStdString().c_str());
    QTextEdit *show = new QTextEdit();
    QString tmp = folderPath;
    tmp += "/log.txt";
    FILE *fp = fopen(tmp.toStdString().c_str(), "r");
    if(!fp) {
        QMessageBox::critical(this, "critical", "cannot read file");
        return;
    }
    char buffer[4096];
    while(fgets(buffer, 4095, fp)) {
        show -> insertPlainText(buffer);
    }
    show -> show();
}
