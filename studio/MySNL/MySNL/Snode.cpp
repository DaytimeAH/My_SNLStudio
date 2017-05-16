#include <iostream>
#include "Snode.h"
using namespace std;

///display()

void Snode::display(string& sep)
{
	cout<<sep;
    cout<<"Snode ";
    cout<<endl;
}

void ExpK::display(string& sep)
{
	cout<<sep;
    cout<<"ExpK ";
}

void OpK::display(string& sep)
{
    ExpK::display(sep);
    cout<<"Op "<<this->op<<endl;
    sep.append("  ");
    this->left->display(sep);
    this->right->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void Const::display(string& sep)
{
    ExpK::display(sep);
    cout<<"Const "<<this->value;
    cout<<endl;
}

void IdV::display(string& sep)
{
    ExpK::display(sep);
    cout<<"IdV "<<this->name;
    cout<<endl;
}

void StmtK::display(string& sep)
{
	cout<<sep;
    cout<<"StmtK ";
}

void IfK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"If "<<endl;
    sep.append("  ");
    this->condtE->display(sep);
    this->thenS->display(sep);
    this->elseS->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void WhileK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"While "<<endl;
    sep.append("  ");
    this->condtE->display(sep);
    this->bodyS->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void AssignK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"Assign "<<endl;
    sep.append("  ");
    this->left->display(sep);
    this->right->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void ReadK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"Read "<<this->id;
    cout<<endl;
}

void WriteK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"Write "<<this->id;
    cout<<endl;
}

void CallK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"Call "<<endl;
    sep.append("  ");
    this->name->display(sep);
    this->param->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void ReturnK::display(string& sep)
{
    StmtK::display(sep);
    cout<<"Return";
    cout<<endl;
}

void DecK::display(string& sep)
{
	cout<<sep;
    cout<<"DecK ";
}

void ArrayK::display(string& sep)
{
    DecK::display(sep);
    cout<<"Array "<<"["<<this->low<<".."<<this->top;
    cout<<endl;
}

void CharK::display(string& sep)
{
    DecK::display(sep);
    cout<<"Char ";
    for(vector<string>::iterator it = this->ids.begin(); it != this->ids.end(); ++it)
    {
	    cout<<sep;
        cout<<*it<<" ";
    }
}

void IntegerK::display(string& sep)
{
    DecK::display(sep);
    cout<<"Integer ";
    for(vector<string>::iterator it = this->ids.begin(); it != this->ids.end(); ++it)
    {
	    cout<<sep;
        cout<<*it<<" ";
    }
}

void RecordK::display(string& sep)
{
    DecK::display(sep);
    cout<<"Record"<<endl;
    if(this->child != nullptr)
        this->child->display(sep);
}

void IdK::display(string& sep)
{
    DecK::display(sep);
    cout<<this->type<<" ";
    cout<<this->id<<endl;
}

void ProK::display(string& sep)
{
    cout<<sep;
    cout<<"ProK "<<endl;
    sep.append("  ");
    if(this->programHead)
        this->programHead->display(sep);
    if(this->declarePart)
        this->declarePart->display(sep);
    if(this->programBody)
        this->programBody->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
}

void PheadK::display(string& sep)
{
    cout<<sep;
    cout<<this->programName<<endl;
}

void TypeK::display(string& sep)
{
    cout<<sep;
    cout<<"TypeK"<<endl;
    sep.append("  ");
    this->child->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
    if(this->sibling)
        this->sibling->display(sep);
}

void VarK::display(string& sep)
{
    cout<<sep;
    cout<<"VarK"<<endl;
    sep.append("  ");
    this->child->display(sep);
    sep.erase(sep.end()-3, sep.end()-1);
    if(this->sibling)
        this->sibling->display(sep);
}

void ProcDecK::display(string& sep)
{
    cout<<sep;
    cout<<"ProcDecK "<<this->procName<<endl;
    if(this->sibling)
        this->sibling->display(sep);
}

void StmLK::display(string& sep)
{
    cout<<sep;
    cout<<"StmLK"<<endl;
    sep.append("  ");
    for(vector<Snode*>::iterator it = this->stmts.begin(); it != this->stmts.end(); ++it)
    {
        (*it)->display(sep);
    }
}
