#ifndef SNODE_H_INCLUDED
#define SNODE_H_INCLUDED

#ifndef __NODE_H__
#define __NODE_H__


#include <string>
#include <vector>
using namespace std;

//Snode : the base class
class Snode
{
public:
    virtual void display(string& sep);
};

//ExpK
class ExpK : public Snode
{
public:
    void display(string& sep);
    //ExpK members
};

//OpK :
class OpK : public ExpK
{
public:
    void display(string& sep);
    //OpK members
    char op;
    Snode * left;
    Snode * right;
};

//Const :
class Const : public ExpK
{
public:
    void display(string& sep);
    //Const members
    int value;
};

class IdV : public ExpK
{
public:
    void display(string& sep);
    //IdV members
    string name;
};

//StmtK
class StmtK : public Snode
{
public:
    void display(string& sep);
    //StmtK members;
};


//IfK
class IfK : public StmtK
{
public:
    void display(string& sep);
    //IfK members
    Snode * condtE;
    Snode * thenS;
    Snode * elseS;
};

//WhileK
class WhileK : public StmtK
{
public:
    void display(string& sep);
    //WhileK members
    Snode * condtE;
    Snode * bodyS;
};

//AssignK
class AssignK : public StmtK
{
public:
    void display(string& sep);
    //Assign members
    Snode * left;
    Snode * right;
};

//ReadK
class ReadK : public StmtK
{
public:
    void display(string& sep);
    //ReadK members
    string id;
};

//WriteK
class WriteK : public StmtK
{
public:
    void display(string& sep);
    //WriteK members
    string id;
};

//CallK
class CallK : public StmtK
{
public:
    void display(string& sep);
    //CallK members
    Snode * name;
    Snode * param;
};

//ReturnK
class ReturnK : public StmtK
{
public:
    void display(string& sep);
    //ReturnK members
    //nothing here
};

//DecK
class DecK : public Snode
{
public:
    void display(string& sep);
    //DecK members
};

//ArrayK
class ArrayK : public DecK
{
public:
    void display(string& sep);
    //ArrayK members
    string typeName;
    int low;
    int top;
};

//CharK
class CharK : public DecK
{
public:
    void display(string& sep);
    //CharK members
    vector<string> ids;
};

//IntegerK
class IntegerK : public DecK
{
public:
    void display(string& sep);
    //IntegerK members
    vector<string> ids;
};

//RecordK
class RecordK : public DecK
{
public:
    void display(string& sep);
    //Record members
    Snode * child;
};

class IdK : public DecK
{
public:
    void display(string& sep);
    //IdK members
    string * type;
    string id;
};

//ProK    root
class ProK : public Snode
{
public:
    void display(string& sep);
    //ProK members
    Snode * programHead;
    Snode * declarePart;
    Snode * programBody;
};

//PheadK
class PheadK : public Snode
{
public:
    void display(string& sep);
    //PheadK members
    string programName;
};

//TypeK
class TypeK : public Snode
{
public:
    void display(string& sep);
    //TypeK members
    Snode * child;
    Snode * sibling;
};

//VarK
class VarK : public Snode
{
public:
    void display(string& sep);
    //VarK members
    Snode * child;
    Snode * sibling;
};

//ProcDecK
class ProcDecK : public Snode
{
public:
    void display(string& sep);
    //ProcDecK members
    string procName;
    Snode * params;
    Snode * body;
    Snode * sibling;
};

//StmLK
class StmLK : public Snode
{
public:
    void display(string& sep);
    //StmLK members
    vector<Snode*> stmts;
};

#endif

#endif // SNODE_H_INCLUDED
