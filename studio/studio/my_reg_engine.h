#ifndef MY_REG_ENGINE_H
#define MY_REG_ENGINE_H
#include <map>
#include <QString>
#include <stdint.h>
#include <vector>

#define _MRE_FORCE_ (1)
#define _MRE_ADD_ (0)

struct _MRE_STATUS_ {
    std::map<char, _MRE_STATUS_ *> outEdges;
    QString *status = NULL;
    _MRE_STATUS_ *add(char ch, _MRE_STATUS_ *toAdd, int type) {
        if(type == _MRE_ADD_) {
            if(outEdges.count(ch)) {
                return outEdges[ch];
            }
        }
        outEdges[ch] = toAdd;
        return toAdd;
    }
};

class my_reg_engine {
public:
    my_reg_engine();
    void addStatus(QString status, QString &regExp);
    QString *parse2Token(QString &str) const;
private:
    void find_match(QString &, int startFrom);
    _MRE_STATUS_ *start;
};

#endif // MY_REG_ENGINE_H
