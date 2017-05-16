#ifndef RESERCHLR1_H_INCLUDED
#define RESERCHLR1_H_INCLUDED

#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include "stdio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stack>
#include "scanner.h"

struct grammar
{
    string vn;
    vector<string>s;
};

struct tree
{
    tree() {};
    int line;
    string father;
    vector<tree*> son;
};

struct statues
{
    int c;
    tree* next;
    statues()
    {
        c = 0;
    }
    statues(string now,string value,int line)
    {
        tree* t;
        t = new tree();
        t->line = line;
        t->father = now;
        t->son.clear();
        tree* t_son;
        t_son = new tree();
        t_son->father = value;
        t_son->son.clear();
        t->son.push_back(t_son);
        next = t;
    }
    statues& operator = (const statues &rhs)
    {
        this->next = rhs.next;
        this->c = rhs.c;
        return *this;
    }
};


class ParserLR1
{
public:
    Token * current;
    bool state = true;
    static ParserLR1* getParser(Token * head, string file)
    {
        return (new ParserLR1(head, file));
    }
    ParserLR1(Token * head, string file)
    {
        current = head;
        vn_num = 67;
        vt_num = 45;
        closure_num = 411;
        ofs.open(file);
    }
    void readLR1();
    vector<string> split(string& str, const char* c);
    int reserchLR1(string next,string value,int line);
    void printftree(int i, tree* root);
    int GotoLr1(int grammar);
    void printjason(tree* root);
    void readTokens();
    void analysisLr1();
    int parseLR1();
    int parse();
private:
    ofstream ofs;
    grammar g[200];
    int vn_num;
    int vt_num;
    int closure_num;
    int lr1action[1000][1000], lr1goto[1000][1000];
    stack<string> symbol;
    stack<statues> condition;
    map<string, int> vt_map;
    map<string, int> vn_map;
    string vn[1000];
    string vt[1000];
    vector<Token> input;
};





#endif // RESERCHLR1_H_INCLUDED
