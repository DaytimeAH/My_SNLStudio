#include "lex_analyzer.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <QRegExp>
#include <QStringList>

lex_analyzer::lex_analyzer(QString languageConf, QString highLightConf){
    statusNum = 0;
    parsedHtml.clear();
    regEngine = new my_reg_engine;
    readConf(languageConf, LA_LANG_CONF);
    readConf(highLightConf, LA_HILI_CONF);
}

int lex_analyzer::readConf(QString conf, int type){
    QByteArray Conf = conf.toLatin1();
    FILE* fp = fopen(Conf.data(), "r");
    if(!fp) {
        return 0;
    }
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    if(type == LA_HILI_CONF) {
        status2Color.clear();
        hili.ParseStream(is);
        QString tmpStatus, tmpColor;
        for(auto &it : hili.GetObject()) {
            tmpStatus = it.name.GetString();
            tmpColor = it.value.GetString();
            status2Color[tmpStatus] = tmpColor;
        }
        if(!status2Color.count("normal")) {
            status2Color["normal"] = "#FFFFFF";
        }
    }
    if(type == LA_LANG_CONF) {
        lang.ParseStream(is);
        statusNum = 0;
        QString tmpRegExp;
        for(auto &it : lang.GetObject()) {
            tmpRegExp = it.value.GetString();
            regEngine -> addStatus(it.name.GetString(), tmpRegExp);
        }
    }
    return 1;
}

QString lex_analyzer::highlightStr(QString str) {
    int len = str.length();
    std::queue<std::pair<int, QString> > wc;
    for(int i = 0; i < len; i++) {
        QString rval;
        if(str[i].isSpace()) {
            int lval = i;
            QChar tmp = str[i];
            for(;;) {
                if(tmp == '\t') {
                    rval += "&emsp;";
                } else if(tmp == '\n') {
                    rval += "<br>";
                } else if(tmp.isSpace()) {
                    rval += "&nbsp;";
                } else {
                    wc.push(std::make_pair(lval, rval));
                    rval.clear();
                    break;
                }
                tmp = str[++i];
            }
        }
    }
    QString strHtml;
    QStringList list = str.split(QRegExp("\\s+"));
    if(!wc.empty()) {
        if(!wc.front().first) {
            strHtml += wc.front().second;
            wc.pop();
        }
    }
    for(auto it : list) {
        if(it.isEmpty()) {
            continue;
        }
        QChar rep = '&';
        it.replace(rep, "&amp;");
        rep = '<';
        it.replace(rep, "&lt;");
        rep = '>';
        it.replace(rep, "&gt;");
        rep = '\"';
        it.replace(rep, "&quot;");
        rep = '\'';
        it.replace(rep, "&apos;");
        parseSingleToken(it);
        strHtml += getRegex();
        if(!wc.empty()) {
            strHtml += wc.front().second;
            wc.pop();
        }
    }
    return strHtml;
}

QString &lex_analyzer::getRegex() {
    parsedHtml = "<font color = \"" \
                 + status2Color\
                 [ regex && (status2Color.count(*regex))\
                 ? *regex\
                 : "normal"]\
                 + "\" >"\
                 + parsedHtml\
                 + "</font>";
    if(regex && ((*regex == "type") || (*regex == "define"))) {
        parsedHtml = "<b>" + parsedHtml + "</b>";
    }
    return parsedHtml;
}

int lex_analyzer::parseSingleToken(QString &str){
    parsedHtml = str;
    regex = regEngine -> parse2Token(str);

    return 1;
}
