#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include "Snode.h"
#include "scanner.h"

class Parser
{
    Token * cur_token;
    Token * pre_token;

    Parser(Token * head)
    {
        cur_token = head;
    }
public:
    bool state = true;
public:
    static Parser* getParser(Token * head)
    {
        return (new Parser(head));
    }
public:


public:
    void Program();

private:
    void ProgramHead();
    void ProgramName();
    void DeclarePart();
    void TypeDecPart();
    void TypeDec();
    void TypeDecList();
    void TypeDecMore();
    void TypeId();
    void TypeDef();
    void BaseType();
    void StructureType();
    void ArrayType();
    void Low();
    void Top();
    void RecType();
    void FieldDecList();
    void FieldDecMore();
    void IdList();
    void IdMore();
    void VarDecPart();
    void VarDec();
    void VarDecList();
    void VarDecMore();
    void VarIdList();
    void VarIdMore();
    void ProcDecPart();
    void ProcDec();
    void ProcDecMore();
    void ProcName();
    void ParamList();
    void ParamDecList();
    void ParamMore();
    void Param();
    void FormList();
    void FidMore();
    void ProcBody();
    void ProgramBody();
    void StmList();
    void StmMore();
    void Stm();
    void AssCall();
    void AssignmentRest();
    void ConditionalStm();
    void LoopStm();
    void InputStm();
    void Invar();
    void OutputStm();
    void ReturnStm();
    void CallStmRest();
    void ActParamList();
    void ActParamMore();
    void RelExp();
    void OtherRelE();
    void Exp();
    void OtherTerm();
    void Term();
    void OtherFactor();
    void Factor();
    void Variable();
    void VariMore();
    void FieldVar();
    void FieldVarMore();
    void CmpOp();
    void AddOp();
    void MultOp();
    bool match(LexType lex);
};




#endif // PARSE_H_INCLUDED
