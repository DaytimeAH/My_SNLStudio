#include "my_reg_engine.h"
#include <iostream>

my_reg_engine::my_reg_engine() {
    start = new _MRE_STATUS_;
}

void my_reg_engine::addStatus(QString status, QString &regExp) {
    int len = regExp.length();
    std::vector<_MRE_STATUS_ *> ors;
    _MRE_STATUS_ *plus = NULL;
    _MRE_STATUS_ *any = NULL;
    _MRE_STATUS_ *any2 = NULL;
    _MRE_STATUS_ *now = start;
    _MRE_STATUS_ *last = now;
    int i = 0;
    for(; i < len; i++) {
        if(regExp[i] == '[') {
            if((!i) || regExp[i-1] != '\\') {
                last = now;
                continue;
            }
        }
        if(regExp[i] == ']') {
            if((!i) || regExp[i-1] != '\\') {
                ors.push_back(now);
                _MRE_STATUS_ *newState = new _MRE_STATUS_;
                for(auto it : ors) {
                    it -> add((char) 0, newState, _MRE_FORCE_);
                }
                now = newState;
                ors.clear();
                continue;
            }
        }
        if(regExp[i] == '|') {
            if((!i) || regExp[i-1] != '\\') {
                ors.push_back(now);
                now = last;
                continue;
            }
        }
        if(regExp[i] == '+') {
            if((!i) || regExp[i-1] != '\\') {
                if(!plus) {
                    plus = now;
                } else {
                    for(auto it : plus -> outEdges) {
                       now ->add(it.first, it.second, _MRE_ADD_);
                    }
                    plus = NULL;
                }
                continue;
            }
        }
        if(regExp[i] == '*') {
            if((!i) || regExp[i-1] != '\\') {
                if(!any) {
                    any = now;
                } else {
                    for(auto it : any -> outEdges) {
                       now ->add(it.first, it.second, _MRE_ADD_);
                    }
                    any2 = any;
                    any = NULL;
                }
                continue;
            }
        }
        if(regExp[i] == '\\') {
            if((!i) || regExp[i-1] != '\\') {
                continue;
            }
        }
        if(regExp[i] == '.') {
            if((!i) || regExp[i-1] != '\\') {
                _MRE_STATUS_ *next = new _MRE_STATUS_;
                for(int i = 1; i < 127; i++) {
                    now -> add(i, next, _MRE_ADD_);
                }
                now = next;
                continue;
            }
        }
        now = now ->add(regExp[i].toLatin1(), new _MRE_STATUS_, _MRE_ADD_);

        if(any2) {
            for(auto it : now -> outEdges) {
               any2 ->add(it.first, it.second, _MRE_FORCE_);
            }
            any2 = NULL;
        }
    }
    if(i == len) {
        //std::cout << status.toStdString() << std::endl;
        now -> status = new QString(status);
    }
}


QString *my_reg_engine::parse2Token(QString &str) const {
    _MRE_STATUS_ *now = start;
    int len = str.length();
    int i = 0;
    for(; i < len; i++) {
        if(now->outEdges.count(str[i].toLatin1())) {
            now = now ->outEdges[str[i].toLatin1()];
        } else {
            break;
        }
        while(now -> outEdges.count(0)) {
            now = now -> outEdges[0];
        }
    }
    if(i == len) {
        return now -> status;
    }
    return NULL;
}
