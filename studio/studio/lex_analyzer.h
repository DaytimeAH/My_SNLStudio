#ifndef LEX_ANALYZER_H
#define LEX_ANALYZER_H

#include <QString>
#include <map>
#include "rapidjson/document.h"
#include "my_reg_engine.h"

#define LA_LANG_CONF (1)
#define LA_HILI_CONF (2)
#include "rapidjson/filereadstream.h"
#include <QString>
#include <QByteArray>

class lex_analyzer {
public:
    lex_analyzer(QString languageConf, QString highLightConf);
    int readConf(QString, int);
    void newLine();
    QString highlightStr(QString);

private:
    QString &getRegex();
    int parseSingleToken(QString &);
    QString *regex;
    QString parsedHtml;
    QString langPath, hiliPath;
    rapidjson::Document lang, hili;
    my_reg_engine *regEngine;
    std::map<QString, QString> status2Color;
    int statusNum;
};

#endif // LEX_ANALYZER_H
