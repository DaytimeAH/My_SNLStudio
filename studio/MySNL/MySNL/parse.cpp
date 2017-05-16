#include "parse.h"
#include <iostream>
using namespace std;


void Parser::Program()
{
    ProgramHead();
    DeclarePart();
    ProgramBody();
    match(DOT);
    return;
}

void Parser::ProgramHead()
{
    match(PROGRAM);
    ProgramName();
    return;
}

void Parser::ProgramName()
{
    match(ID);
    return;
}

void Parser::DeclarePart()
{
    TypeDecPart();
    VarDecPart();
    ProcDecPart();
    return;
}

void Parser::TypeDecPart()
{
    if(cur_token->getLex() == PROCEDURE || cur_token->getLex() ==  VAR || cur_token->getLex() ==  BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == TYPE)
    {
        TypeDec();
    }
    return;
}

void Parser::TypeDec()
{
    match(TYPE);
    TypeDecList();
    return;
}

void Parser::TypeDecList()
{
    TypeId();
    match(EQ);
    TypeDef();
    match(SEMI);
    TypeDecMore();
    return;
}

void Parser::TypeDecMore()
{
    if(cur_token->getLex() == PROCEDURE || cur_token->getLex() ==  VAR || cur_token->getLex() ==  BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == ID)
    {
        TypeDecList();
    }
    return;
}

void Parser::TypeId()
{
    match(ID);
    return;
}

void Parser::TypeDef()
{
    if(cur_token->getLex() == INTEGER || cur_token->getLex() ==  CHAR)
    {
        BaseType();
    }
    else if(cur_token->getLex() == ARRAY || cur_token->getLex() ==  RECORD)
    {
        StructureType();
    }
    else if(cur_token->getLex() == ID)
    {
        match(ID);
    }
    return;
}

void Parser::BaseType()
{
    if(cur_token->getLex() == INTEGER)
    {
        match(INTEGER);
    }
    else if(cur_token->getLex() == CHAR)
    {
        match(CHAR);
    }
    return;
}

void Parser::StructureType()
{
    if(cur_token->getLex() == ARRAY)
    {
        ArrayType();
    }
    else if(cur_token->getLex() == RECORD)
    {
        RecType();
    }
    return;
}

void Parser::ArrayType()
{
    match(ARRAY);
    match(LMIDPAREN);
    Low();
    match(UNDERRANGE);
    Top();
    match(RMIDPAREN);
    match(OF);
    BaseType();
    return;
}

void Parser::Low()
{
    match(INTC_VAL);
    return;
}

void Parser::Top()
{
    match(INTC_VAL);
    return;
}

void Parser::RecType()
{
    match(RECORD);
    FieldDecList();
    match(END);
    return;
}

void Parser::FieldDecList()
{
    if(cur_token->getLex() == INTEGER || cur_token->getLex() ==  CHAR)
    {
        BaseType();
        IdList();
        match(SEMI);
        FieldDecMore();
    }
    else if(cur_token->getLex() == ARRAY)
    {
        ArrayType();
        IdList();
        match(SEMI);
        FieldDecMore();
    }
    return;
}

void Parser::FieldDecMore()
{
    if(cur_token->getLex() == END)
    {
        return;
    }
    else if(cur_token->getLex() == INTEGER || cur_token->getLex() ==  CHAR || cur_token->getLex() ==  ARRAY)
    {
        FieldDecList();
    }
    return;
}

void Parser::IdList()
{
    match(ID);
    IdMore();
    return;
}

void Parser::IdMore()
{
    if(cur_token->getLex() == SEMI)
    {
        return;
    }
    else if(cur_token->getLex() == COMMA)
    {
        match(COMMA);
        IdList();
    }
    return;
}

void Parser::VarDecPart()
{
    if(cur_token->getLex() == PROCEDURE || cur_token->getLex() ==  BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == VAR)
    {
        VarDec();
    }
    return;
}

void Parser::VarDec()
{
    match(VAR);
    VarDecList();
    return;
}

void Parser::VarDecList()
{
    TypeDef();
    VarIdList();
    match(SEMI);
    VarDecMore();
    return;
}

void Parser::VarDecMore()
{
    if(cur_token->getLex() == PROCEDURE || cur_token->getLex() ==  BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == ID || cur_token->getLex() ==  INTEGER || cur_token->getLex() ==  CHAR || cur_token->getLex() ==  ARRAY || cur_token->getLex() ==  RECORD)
    {
        VarDecList();
    }
    return;
}

void Parser::VarIdList()
{
    match(ID);
    VarIdMore();
    return;
}

void Parser::VarIdMore()
{
    if(cur_token->getLex() == SEMI)
    {
        return;
    }
    else if(cur_token->getLex() == COMMA)
    {
        match(COMMA);
        VarIdList();
    }
    return;
}

void Parser::ProcDecPart()
{
    if(cur_token->getLex() == BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == PROCEDURE)
    {
        ProcDec();
    }
    else if(cur_token->getLex() == TYPE || cur_token->getLex() ==  VAR)
    {
        DeclarePart();
    }
    return;
}

void Parser::ProcDec()
{
    match(PROCEDURE);
    ProcName();
    match(LPAREN);
    ParamList();
    match(RPAREN);
    match(SEMI);
    ProcDecPart();
    ProcBody();
    ProcDecMore();
    return;
}

void Parser::ProcDecMore()
{
    if(cur_token->getLex() == BEGIN)
    {
        return;
    }
    else if(cur_token->getLex() == PROCEDURE)
    {
        ProcDec();
    }
    return;
}

void Parser::ProcName()
{
    match(ID);
    return;
}

void Parser::ParamList()
{
    if(cur_token->getLex() == RPAREN)
    {
        return;
    }
    else if(cur_token->getLex() == VAR || cur_token->getLex() ==  ID || cur_token->getLex() ==  INTEGER || cur_token->getLex() ==  CHAR || cur_token->getLex() ==  ARRAY || cur_token->getLex() ==  RECORD)
    {
        ParamDecList();
    }
    return;
}

void Parser::ParamDecList()
{
    Param();
    ParamMore();
    return;
}

void Parser::ParamMore()
{
    if(cur_token->getLex() == RPAREN)
    {
        return;
    }
    else if(cur_token->getLex() == SEMI)
    {
        match(SEMI);
        ParamDecList();
    }
    return;
}

void Parser::Param()
{
    if(cur_token->getLex() == ID || cur_token->getLex() ==  INTEGER || cur_token->getLex() ==  CHAR || cur_token->getLex() ==  ARRAY || cur_token->getLex() ==  RECORD)
    {
        TypeDef();
        FormList();
    }
    else if(cur_token->getLex() == VAR)
    {
        match(VAR);
        TypeDef();
        FormList();
    }
    return;
}

void Parser::FormList()
{
    match(ID);
    FidMore();
    return;
}

void Parser::FidMore()
{
    if(cur_token->getLex() == SEMI || cur_token->getLex() ==  RPAREN)
    {
        return;
    }
    else if(cur_token->getLex() == COMMA)
    {
        match(COMMA);
        FormList();
    }
    return;
}

void Parser::ProcBody()
{
    ProgramBody();
    return;
}

void Parser::ProgramBody()
{
    match(BEGIN);
    StmList();
    match(END);
    return;
}

void Parser::StmList()
{
    Stm();
    StmMore();
    return;
}

void Parser::StmMore()
{
    if(cur_token->getLex() == ENDWH || cur_token->getLex() ==  ELSE || cur_token->getLex() ==  FI || cur_token->getLex() ==  END)
    {
        return;
    }
    else if(cur_token->getLex() == SEMI)
    {
        match(SEMI);
        StmList();
    }
    return;
}

void Parser::Stm()
{
    if(cur_token->getLex() == IF)
    {
        ConditionalStm();
    }
    else if(cur_token->getLex() == WHILE)
    {
        LoopStm();
    }
    else if(cur_token->getLex() == READ)
    {
        InputStm();
    }
    else if(cur_token->getLex() == WRITE)
    {
        OutputStm();
    }
    else if(cur_token->getLex() == RETURN)
    {
        ReturnStm();
    }
    else if(cur_token->getLex() == ID)
    {
        match(ID);
        AssCall();
    }
    return;
}

void Parser::AssCall()
{
    if(cur_token->getLex() == ASSIGN || cur_token->getLex() ==  LMIDPAREN || cur_token->getLex() ==  DOT)
    {
        AssignmentRest();
    }
    else if(cur_token->getLex() == LPAREN)
    {
        CallStmRest();
    }
    return;
}

void Parser::AssignmentRest()
{
    VariMore();
    match(ASSIGN);
    Exp();
    return;
}

void Parser::ConditionalStm()
{
    match(IF);
    RelExp();
    match(THEN);
    StmList();
    match(ELSE);
    StmList();
    match(FI);
    return;
}

void Parser::LoopStm()
{
    match(WHILE);
    RelExp();
    match(DO);
    StmList();
    match(ENDWH);
    return;
}

void Parser::InputStm()
{
    match(READ);
    match(LPAREN);
    Invar();
    match(RPAREN);
    return;
}

void Parser::Invar()
{
    match(ID);
    return;
}

void Parser::OutputStm()
{
    match(WRITE);
    match(LPAREN);
    Exp();
    match(RPAREN);
    return;
}

void Parser::ReturnStm()
{
    match(RETURN);
    return;
}

void Parser::CallStmRest()
{
    match(LPAREN);
    ActParamList();
    match(RPAREN);
    return;
}

void Parser::ActParamList()
{
    if(cur_token->getLex() == RPAREN)
    {
        return;
    }
    else if(cur_token->getLex() == LPAREN || cur_token->getLex() ==  INTC_VAL || cur_token->getLex() ==  ID)
    {
        Exp();
        ActParamMore();
    }
    return;
}

void Parser::ActParamMore()
{
    if(cur_token->getLex() == RPAREN)
    {
        return;
    }
    else if(cur_token->getLex() == COMMA)
    {
        match(COMMA);
        ActParamList();
    }
    return;
}

void Parser::RelExp()
{
    Exp();
    OtherRelE();
    return;
}

void Parser::OtherRelE()
{
    CmpOp();
    Exp();
    return;
}

void Parser::Exp()
{
    Term();
    OtherTerm();
    return;
}

void Parser::OtherTerm()
{
    if(cur_token->getLex() == RMIDPAREN || cur_token->getLex() ==  RPAREN || cur_token->getLex() ==  LT || cur_token->getLex() ==  EQ || cur_token->getLex() ==  COMMA || cur_token->getLex() ==  DO || cur_token->getLex() ==  THEN || cur_token->getLex() ==  SEMI || cur_token->getLex() ==  ENDWH || cur_token->getLex() ==  ELSE || cur_token->getLex() ==  FI || cur_token->getLex() ==  END)
    {
        return;
    }
    else if(cur_token->getLex() == PLUS || cur_token->getLex() ==  MINUS)
    {
        AddOp();
        Exp();
    }
    return;
}

void Parser::Term()
{
    Factor();
    OtherFactor();
    return;
}

void Parser::OtherFactor()
{
    if(cur_token->getLex() == PLUS || cur_token->getLex() ==  MINUS || cur_token->getLex() ==  RMIDPAREN || cur_token->getLex() ==  RPAREN || cur_token->getLex() ==  LT || cur_token->getLex() ==  EQ || cur_token->getLex() ==  COMMA || cur_token->getLex() ==  DO || cur_token->getLex() ==  THEN || cur_token->getLex() ==  SEMI || cur_token->getLex() ==  ENDWH || cur_token->getLex() ==  ELSE || cur_token->getLex() ==  FI || cur_token->getLex() ==  END)
    {
        return;
    }
    else if(cur_token->getLex() == TIMES || cur_token->getLex() ==  DIVIDE)
    {
        MultOp();
        Term();
    }
    return;
}

void Parser::Factor()
{
    if(cur_token->getLex() == LPAREN)
    {
        match(LPAREN);
        Exp();
        match(RPAREN);
    }
    else if(cur_token->getLex() == INTC_VAL)
    {
        match(INTC_VAL);
    }
    else if(cur_token->getLex() == CHAR_VAL)
    {
        match(CHAR_VAL);
    }
    else if(cur_token->getLex() == ID)
    {
        Variable();
    }
    return;
}

void Parser::Variable()
{
    match(ID);
    VariMore();
    return;
}

void Parser::VariMore()
{
    if(cur_token->getLex() == ASSIGN || cur_token->getLex() ==  TIMES || cur_token->getLex() ==  DIVIDE || cur_token->getLex() ==  PLUS || cur_token->getLex() ==  MINUS || cur_token->getLex() ==  RMIDPAREN || cur_token->getLex() ==  RPAREN || cur_token->getLex() ==  LT || cur_token->getLex() ==  EQ || cur_token->getLex() ==  COMMA || cur_token->getLex() ==  DO || cur_token->getLex() ==  THEN || cur_token->getLex() ==  SEMI || cur_token->getLex() ==  ENDWH || cur_token->getLex() ==  ELSE || cur_token->getLex() ==  FI || cur_token->getLex() ==  END)
    {
        return;
    }
    else if(cur_token->getLex() == LMIDPAREN)
    {
        match(LMIDPAREN);
        Exp();
        match(RMIDPAREN);
    }
    else if(cur_token->getLex() == DOT)
    {
        match(DOT);
        FieldVar();
    }
    return;
}

void Parser::FieldVar()
{
    match(ID);
    FieldVarMore();
    return;
}

void Parser::FieldVarMore()
{
    if(cur_token->getLex() == ASSIGN || cur_token->getLex() ==  TIMES || cur_token->getLex() ==  DIVIDE || cur_token->getLex() ==  PLUS || cur_token->getLex() ==  MINUS || cur_token->getLex() ==  RMIDPAREN || cur_token->getLex() ==  RPAREN || cur_token->getLex() ==  LT || cur_token->getLex() ==  EQ || cur_token->getLex() ==  COMMA || cur_token->getLex() ==  DO || cur_token->getLex() ==  THEN || cur_token->getLex() ==  SEMI || cur_token->getLex() ==  ENDWH || cur_token->getLex() ==  ELSE || cur_token->getLex() ==  FI || cur_token->getLex() ==  END)
    {
        return;
    }
    else if(cur_token->getLex() == LMIDPAREN)
    {
        match(LMIDPAREN);
        Exp();
        match(RMIDPAREN);
    }
    return;
}

void Parser::CmpOp()
{
    if(cur_token->getLex() == LT)
    {
        match(LT);
    }
    else if(cur_token->getLex() == EQ)
    {
        match(EQ);
    }
    return;
}

void Parser::AddOp()
{
    if(cur_token->getLex() == PLUS)
    {
        match(PLUS);
    }
    else if(cur_token->getLex() == MINUS)
    {
        match(MINUS);
    }
    return;
}

void Parser::MultOp()
{
    if(cur_token->getLex() == TIMES)
    {
        match(TIMES);
    }
    else if(cur_token->getLex() == DIVIDE)
    {
        match(DIVIDE);
    }
    return;
}

bool Parser::match(LexType lex)
{
	if(!this->state)
	{
		return false;
	}
    if(cur_token->getLex() == lex)
    {
        //cout<<cur_token->getSem()<<endl;
        pre_token = cur_token;
        cur_token = cur_token->next;
        return true;
    }
    else
    {
        cout << "line " <<cur_token->getLine()<<" : unexpected token ";
        cout <<cur_token->getLexName()<<" sem: "<<cur_token->getSem()<<endl;
        this->state = false;
        return false;
    }
}
