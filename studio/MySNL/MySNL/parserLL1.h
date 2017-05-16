#ifndef _parserLL1_h
#define _parserLL1_h

#include <cstring>
#include <map>
#include <fstream>
#include "parse.h"

using namespace std;


enum nTerminal
{
    Program = 100,
    ProgramHead,ProgramName,DeclarePart,TypeDecPart,
    TypeDec,TypeDecList,TypeDecMore,TypeId,
    TypeDef,BaseType,StructureType,ArrayType,
    Low,Top,RecType,FieldDecList,
    FieldDecMore,IdList,IdMore,VarDecPart,
    VarDec,VarDecList,VarDecMore,VarIdList,
    VarIdMore,ProcDecPart,ProcDec,ProcDecMore,
    ProcName,ParamList,ParamDecList,ParamMore,
    Param,FormList,FidMore,ProcBody,
    ProgramBody,StmList,StmMore,Stm,
    AssCall,AssignmentRest,ConditionalStm,LoopStm,
    InputStm,Invar,OutputStm,ReturnStm,
    CallStmRest,ActParamList,ActParamMore,RelExp,
    OtherRelE,Exp,OtherTerm,Term,
    OtherFactor,Factor,Variable,VariMore,
    FieldVar,FieldVarMore,CmpOp,AddOp,
    MultOp,HHH,
};


extern map<int, string> Tnode;



class exNode
{
public:
    int len;
    int lst[10];
};

class ParserLL
{
    Token * cur_token;
    Token * pre_token;

public:
    bool state = true;
    static ParserLL* getParser(Token * head)
    {
        return (new ParserLL(head));
    }
    ~ParserLL(){
		output.close();
    }
    void parse();

//    voi
private:
    exNode exnode[66];
    int mp[167][44];
	ofstream output;
    bool match(LexType lex);

    ParserLL(Token * head)
    {
		output.open("C:/Users/DarknessH/Desktop/myIntelliStudio/studio/MySNL/outputTree/Myout");
        cur_token = head;

        memset(mp,-1,sizeof(mp));

        exnode[0].len = 4;
        exnode[0].lst[3] = ProgramHead;
        exnode[0].lst[2] = DeclarePart;
        exnode[0].lst[1] = ProgramBody;
        exnode[0].lst[0] = DOT;
        exnode[1].len = 2;
        exnode[1].lst[1] = PROGRAM;
        exnode[1].lst[0] = ProgramName;
        exnode[2].len = 1;
        exnode[2].lst[0] = ID;
        exnode[3].len = 3;
        exnode[3].lst[2] = TypeDecPart;
        exnode[3].lst[1] = VarDecPart;
        exnode[3].lst[0] = ProcDecPart;
        exnode[4].len = 1;
        exnode[4].lst[0] = HHH;
        exnode[5].len = 1;
        exnode[5].lst[0] = TypeDec;
        exnode[6].len = 2;
        exnode[6].lst[1] = TYPE;
        exnode[6].lst[0] = TypeDecList;
        exnode[7].len = 5;
        exnode[7].lst[4] = TypeId;
        exnode[7].lst[3] = EQ;
        exnode[7].lst[2] = TypeDef;
        exnode[7].lst[1] = SEMI;
        exnode[7].lst[0] = TypeDecMore;
        exnode[8].len = 1;
        exnode[8].lst[0] = HHH;
        exnode[9].len = 1;
        exnode[9].lst[0] = TypeDecList;
        exnode[10].len = 1;
        exnode[10].lst[0] = ID;
        exnode[11].len = 1;
        exnode[11].lst[0] = BaseType;
        exnode[12].len = 1;
        exnode[12].lst[0] = StructureType;
        exnode[13].len = 1;
        exnode[13].lst[0] = ID;
        exnode[14].len = 1;
        exnode[14].lst[0] = INTEGER;
        exnode[15].len = 1;
        exnode[15].lst[0] = CHAR;
        exnode[16].len = 1;
        exnode[16].lst[0] = ArrayType;
        exnode[17].len = 1;
        exnode[17].lst[0] = RecType;
        exnode[18].len = 8;
        exnode[18].lst[7] = ARRAY;
        exnode[18].lst[6] = LMIDPAREN;
        exnode[18].lst[5] = Low;
        exnode[18].lst[4] = UNDERRANGE;
        exnode[18].lst[3] = Top;
        exnode[18].lst[2] = RMIDPAREN;
        exnode[18].lst[1] = OF;
        exnode[18].lst[0] = BaseType;
        exnode[19].len = 1;
        exnode[19].lst[0] = INTC_VAL;
        exnode[20].len = 1;
        exnode[20].lst[0] = INTC_VAL;
        exnode[21].len = 3;
        exnode[21].lst[2] = RECORD;
        exnode[21].lst[1] = FieldDecList;
        exnode[21].lst[0] = END;
        exnode[22].len = 4;
        exnode[22].lst[3] = BaseType;
        exnode[22].lst[2] = IdList;
        exnode[22].lst[1] = SEMI;
        exnode[22].lst[0] = FieldDecMore;
        exnode[23].len = 4;
        exnode[23].lst[3] = ArrayType;
        exnode[23].lst[2] = IdList;
        exnode[23].lst[1] = SEMI;
        exnode[23].lst[0] = FieldDecMore;
        exnode[24].len = 1;
        exnode[24].lst[0] = HHH;
        exnode[25].len = 1;
        exnode[25].lst[0] = FieldDecList;
        exnode[26].len = 2;
        exnode[26].lst[1] = ID;
        exnode[26].lst[0] = IdMore;
        exnode[27].len = 1;
        exnode[27].lst[0] = HHH;
        exnode[28].len = 2;
        exnode[28].lst[1] = COMMA;
        exnode[28].lst[0] = IdList;
        exnode[29].len = 1;
        exnode[29].lst[0] = HHH;
        exnode[30].len = 1;
        exnode[30].lst[0] = VarDec;
        exnode[31].len = 2;
        exnode[31].lst[1] = VAR;
        exnode[31].lst[0] = VarDecList;
        exnode[32].len = 4;
        exnode[32].lst[3] = TypeDef;
        exnode[32].lst[2] = VarIdList;
        exnode[32].lst[1] = SEMI;
        exnode[32].lst[0] = VarDecMore;
        exnode[33].len = 1;
        exnode[33].lst[0] = HHH;
        exnode[34].len = 1;
        exnode[34].lst[0] = VarDecList;
        exnode[35].len = 2;
        exnode[35].lst[1] = ID;
        exnode[35].lst[0] = VarIdMore;
        exnode[36].len = 1;
        exnode[36].lst[0] = HHH;
        exnode[37].len = 2;
        exnode[37].lst[1] = COMMA;
        exnode[37].lst[0] = VarIdList;
        exnode[38].len = 1;
        exnode[38].lst[0] = HHH;
        exnode[39].len = 1;
        exnode[39].lst[0] = ProcDec;
        exnode[40].len = 1;
        exnode[40].lst[0] = DeclarePart;
        exnode[41].len = 9;
        exnode[41].lst[8] = PROCEDURE;
        exnode[41].lst[7] = ProcName;
        exnode[41].lst[6] = LPAREN;
        exnode[41].lst[5] = ParamList;
        exnode[41].lst[4] = RPAREN;
        exnode[41].lst[3] = SEMI;
        exnode[41].lst[2] = ProcDecPart;
        exnode[41].lst[1] = ProcBody;
        exnode[41].lst[0] = ProcDecMore;
        exnode[42].len = 1;
        exnode[42].lst[0] = HHH;
        exnode[43].len = 1;
        exnode[43].lst[0] = ProcDec;
        exnode[44].len = 1;
        exnode[44].lst[0] = ID;
        exnode[45].len = 1;
        exnode[45].lst[0] = HHH;
        exnode[46].len = 1;
        exnode[46].lst[0] = ParamDecList;
        exnode[47].len = 2;
        exnode[47].lst[1] = Param;
        exnode[47].lst[0] = ParamMore;
        exnode[48].len = 1;
        exnode[48].lst[0] = HHH;
        exnode[49].len = 2;
        exnode[49].lst[1] = SEMI;
        exnode[49].lst[0] = ParamDecList;
        exnode[50].len = 2;
        exnode[50].lst[1] = TypeDef;
        exnode[50].lst[0] = FormList;
        exnode[51].len = 3;
        exnode[51].lst[2] = VAR;
        exnode[51].lst[1] = TypeDef;
        exnode[51].lst[0] = FormList;
        exnode[52].len = 2;
        exnode[52].lst[1] = ID;
        exnode[52].lst[0] = FidMore;
        exnode[53].len = 1;
        exnode[53].lst[0] = HHH;
        exnode[54].len = 2;
        exnode[54].lst[1] = COMMA;
        exnode[54].lst[0] = FormList;
        exnode[55].len = 1;
        exnode[55].lst[0] = ProgramBody;
        exnode[56].len = 3;
        exnode[56].lst[2] = BEGIN;
        exnode[56].lst[1] = StmList;
        exnode[56].lst[0] = END;
        exnode[57].len = 2;
        exnode[57].lst[1] = Stm;
        exnode[57].lst[0] = StmMore;
        exnode[58].len = 1;
        exnode[58].lst[0] = HHH;
        exnode[59].len = 2;
        exnode[59].lst[1] = SEMI;
        exnode[59].lst[0] = StmList;
        exnode[60].len = 1;
        exnode[60].lst[0] = ConditionalStm;
        exnode[61].len = 1;
        exnode[61].lst[0] = LoopStm;
        exnode[62].len = 1;
        exnode[62].lst[0] = InputStm;
        exnode[63].len = 1;
        exnode[63].lst[0] = OutputStm;
        exnode[64].len = 1;
        exnode[64].lst[0] = ReturnStm;
        exnode[65].len = 2;
        exnode[65].lst[1] = ID;
        exnode[65].lst[0] = AssCall;
        exnode[66].len = 1;
        exnode[66].lst[0] = AssignmentRest;
        exnode[67].len = 1;
        exnode[67].lst[0] = CallStmRest;
        exnode[68].len = 3;
        exnode[68].lst[2] = VariMore;
        exnode[68].lst[1] = ASSIGN;
        exnode[68].lst[0] = Exp;
        exnode[69].len = 7;
        exnode[69].lst[6] = IF;
        exnode[69].lst[5] = RelExp;
        exnode[69].lst[4] = THEN;
        exnode[69].lst[3] = StmList;
        exnode[69].lst[2] = ELSE;
        exnode[69].lst[1] = StmList;
        exnode[69].lst[0] = FI;
        exnode[70].len = 5;
        exnode[70].lst[4] = WHILE;
        exnode[70].lst[3] = RelExp;
        exnode[70].lst[2] = DO;
        exnode[70].lst[1] = StmList;
        exnode[70].lst[0] = ENDWH;
        exnode[71].len = 4;
        exnode[71].lst[3] = READ;
        exnode[71].lst[2] = LPAREN;
        exnode[71].lst[1] = Invar;
        exnode[71].lst[0] = RPAREN;
        exnode[72].len = 1;
        exnode[72].lst[0] = ID;
        exnode[73].len = 4;
        exnode[73].lst[3] = WRITE;
        exnode[73].lst[2] = LPAREN;
        exnode[73].lst[1] = Exp;
        exnode[73].lst[0] = RPAREN;
        exnode[74].len = 1;
        exnode[74].lst[0] = RETURN;
        exnode[75].len = 3;
        exnode[75].lst[2] = LPAREN;
        exnode[75].lst[1] = ActParamList;
        exnode[75].lst[0] = RPAREN;
        exnode[76].len = 1;
        exnode[76].lst[0] = HHH;
        exnode[77].len = 2;
        exnode[77].lst[1] = Exp;
        exnode[77].lst[0] = ActParamMore;
        exnode[78].len = 1;
        exnode[78].lst[0] = HHH;
        exnode[79].len = 2;
        exnode[79].lst[1] = COMMA;
        exnode[79].lst[0] = ActParamList;
        exnode[80].len = 2;
        exnode[80].lst[1] = Exp;
        exnode[80].lst[0] = OtherRelE;
        exnode[81].len = 2;
        exnode[81].lst[1] = CmpOp;
        exnode[81].lst[0] = Exp;
        exnode[82].len = 2;
        exnode[82].lst[1] = Term;
        exnode[82].lst[0] = OtherTerm;
        exnode[83].len = 1;
        exnode[83].lst[0] = HHH;
        exnode[84].len = 2;
        exnode[84].lst[1] = AddOp;
        exnode[84].lst[0] = Exp;
        exnode[85].len = 2;
        exnode[85].lst[1] = Factor;
        exnode[85].lst[0] = OtherFactor;
        exnode[86].len = 1;
        exnode[86].lst[0] = HHH;
        exnode[87].len = 2;
        exnode[87].lst[1] = MultOp;
        exnode[87].lst[0] = Term;
        exnode[88].len = 3;
        exnode[88].lst[2] = LPAREN;
        exnode[88].lst[1] = Exp;
        exnode[88].lst[0] = RPAREN;
        exnode[89].len = 1;
        exnode[89].lst[0] = INTC_VAL;
        exnode[90].len = 1;
        exnode[90].lst[0] = CHAR_VAL;
        exnode[91].len = 1;
        exnode[91].lst[0] = Variable;
        exnode[92].len = 2;
        exnode[92].lst[1] = ID;
        exnode[92].lst[0] = VariMore;
        exnode[93].len = 1;
        exnode[93].lst[0] = HHH;
        exnode[94].len = 3;
        exnode[94].lst[2] = LMIDPAREN;
        exnode[94].lst[1] = Exp;
        exnode[94].lst[0] = RMIDPAREN;
        exnode[95].len = 2;
        exnode[95].lst[1] = DOT;
        exnode[95].lst[0] = FieldVar;
        exnode[96].len = 2;
        exnode[96].lst[1] = ID;
        exnode[96].lst[0] = FieldVarMore;
        exnode[97].len = 1;
        exnode[97].lst[0] = HHH;
        exnode[98].len = 3;
        exnode[98].lst[2] = LMIDPAREN;
        exnode[98].lst[1] = Exp;
        exnode[98].lst[0] = RMIDPAREN;
        exnode[99].len = 1;
        exnode[99].lst[0] = LT;
        exnode[100].len = 1;
        exnode[100].lst[0] = EQ;
        exnode[101].len = 1;
        exnode[101].lst[0] = PLUS;
        exnode[102].len = 1;
        exnode[102].lst[0] = MINUS;
        exnode[103].len = 1;
        exnode[103].lst[0] = TIMES;
        exnode[104].len = 1;
        exnode[104].lst[0] = DIVIDE;

        mp[Program][PROGRAM] = 0;
        mp[ProgramHead][PROGRAM] = 1;
        mp[ProgramName][ID] = 2;
        mp[DeclarePart][TYPE] = 3;
        mp[DeclarePart][VAR] = 3;
        mp[DeclarePart][PROCEDURE] = 3;
        mp[TypeDecPart][PROCEDURE] = 4;
        mp[TypeDecPart][VAR] = 4;
        mp[TypeDecPart][BEGIN] = 4;
        mp[TypeDecPart][TYPE] = 5;
        mp[TypeDec][TYPE] = 6;
        mp[TypeDecList][ID] = 7;
        mp[TypeDecMore][PROCEDURE] = 8;
        mp[TypeDecMore][VAR] = 8;
        mp[TypeDecMore][BEGIN] = 8;
        mp[TypeDecMore][ID] = 9;
        mp[TypeId][ID] = 10;
        mp[TypeDef][INTEGER] = 11;
        mp[TypeDef][CHAR] = 11;
        mp[TypeDef][ARRAY] = 12;
        mp[TypeDef][RECORD] = 12;
        mp[TypeDef][ID] = 13;
        mp[BaseType][INTEGER] = 14;
        mp[BaseType][CHAR] = 15;
        mp[StructureType][ARRAY] = 16;
        mp[StructureType][RECORD] = 17;
        mp[ArrayType][ARRAY] = 18;
        mp[Low][INTC_VAL] = 19;
        mp[Top][INTC_VAL] = 20;
        mp[RecType][RECORD] = 21;
        mp[FieldDecList][INTEGER] = 22;
        mp[FieldDecList][CHAR] = 22;
        mp[FieldDecList][ARRAY] = 23;
        mp[FieldDecMore][END] = 24;
        mp[FieldDecMore][INTEGER] = 25;
        mp[FieldDecMore][CHAR] = 25;
        mp[FieldDecMore][ARRAY] = 25;
        mp[IdList][ID] = 26;
        mp[IdMore][SEMI] = 27;
        mp[IdMore][COMMA] = 28;
        mp[VarDecPart][PROCEDURE] = 29;
        mp[VarDecPart][BEGIN] = 29;
        mp[VarDecPart][VAR] = 30;
        mp[VarDec][VAR] = 31;
        mp[VarDecList][ID] = 32;
        mp[VarDecList][INTEGER] = 32;
        mp[VarDecList][CHAR] = 32;
        mp[VarDecList][ARRAY] = 32;
        mp[VarDecList][RECORD] = 32;
        mp[VarDecMore][PROCEDURE] = 33;
        mp[VarDecMore][BEGIN] = 33;
        mp[VarDecMore][ID] = 34;
        mp[VarDecMore][INTEGER] = 34;
        mp[VarDecMore][CHAR] = 34;
        mp[VarDecMore][ARRAY] = 34;
        mp[VarDecMore][RECORD] = 34;
        mp[VarIdList][ID] = 35;
        mp[VarIdMore][SEMI] = 36;
        mp[VarIdMore][COMMA] = 37;
        mp[ProcDecPart][BEGIN] = 38;
        mp[ProcDecPart][PROCEDURE] = 39;
        mp[ProcDecPart][TYPE] = 40;
        mp[ProcDecPart][VAR] = 40;
        mp[ProcDec][PROCEDURE] = 41;
        mp[ProcDecMore][BEGIN] = 42;
        mp[ProcDecMore][PROCEDURE] = 43;
        mp[ProcName][ID] = 44;
        mp[ParamList][RPAREN] = 45;
        mp[ParamList][VAR] = 46;
        mp[ParamList][ID] = 46;
        mp[ParamList][INTEGER] = 46;
        mp[ParamList][CHAR] = 46;
        mp[ParamList][ARRAY] = 46;
        mp[ParamList][RECORD] = 46;
        mp[ParamDecList][VAR] = 47;
        mp[ParamDecList][ID] = 47;
        mp[ParamDecList][INTEGER] = 47;
        mp[ParamDecList][CHAR] = 47;
        mp[ParamDecList][ARRAY] = 47;
        mp[ParamDecList][RECORD] = 47;
        mp[ParamMore][RPAREN] = 48;
        mp[ParamMore][SEMI] = 49;
        mp[Param][ID] = 50;
        mp[Param][INTEGER] = 50;
        mp[Param][CHAR] = 50;
        mp[Param][ARRAY] = 50;
        mp[Param][RECORD] = 50;
        mp[Param][VAR] = 51;
        mp[FormList][ID] = 52;
        mp[FidMore][SEMI] = 53;
        mp[FidMore][RPAREN] = 53;
        mp[FidMore][COMMA] = 54;
        mp[ProcBody][BEGIN] = 55;
        mp[ProgramBody][BEGIN] = 56;
        mp[StmList][ID] = 57;
        mp[StmList][IF] = 57;
        mp[StmList][READ] = 57;
        mp[StmList][RETURN] = 57;
        mp[StmList][WHILE] = 57;
        mp[StmList][WRITE] = 57;
        mp[StmMore][ENDWH] = 58;
        mp[StmMore][ELSE] = 58;
        mp[StmMore][FI] = 58;
        mp[StmMore][END] = 58;
        mp[StmMore][SEMI] = 59;
        mp[Stm][IF] = 60;
        mp[Stm][WHILE] = 61;
        mp[Stm][READ] = 62;
        mp[Stm][WRITE] = 63;
        mp[Stm][RETURN] = 64;
        mp[Stm][ID] = 65;
        mp[AssCall][ASSIGN] = 66;
        mp[AssCall][LMIDPAREN] = 66;
        mp[AssCall][DOT] = 66;
        mp[AssCall][LPAREN] = 67;
        mp[AssignmentRest][LMIDPAREN] = 68;
        mp[AssignmentRest][DOT] = 68;
        mp[AssignmentRest][ASSIGN] = 68;
        mp[ConditionalStm][IF] = 69;
        mp[LoopStm][WHILE] = 70;
        mp[InputStm][READ] = 71;
        mp[Invar][ID] = 72;
        mp[OutputStm][WRITE] = 73;
        mp[ReturnStm][RETURN] = 74;
        mp[CallStmRest][LPAREN] = 75;
        mp[ActParamList][RPAREN] = 76;
        mp[ActParamList][LPAREN] = 77;
        mp[ActParamList][INTC_VAL] = 77;
        mp[ActParamList][ID] = 77;
        mp[ActParamMore][RPAREN] = 78;
        mp[ActParamMore][COMMA] = 79;
        mp[RelExp][LPAREN] = 80;
        mp[RelExp][INTC_VAL] = 80;
        mp[RelExp][ID] = 80;
        mp[OtherRelE][LT] = 81;
        mp[OtherRelE][EQ] = 81;
        mp[Exp][LPAREN] = 82;
        mp[Exp][INTC_VAL] = 82;
        mp[Exp][ID] = 82;
        mp[OtherTerm][RMIDPAREN] = 83;
        mp[OtherTerm][RPAREN] = 83;
        mp[OtherTerm][LT] = 83;
        mp[OtherTerm][EQ] = 83;
        mp[OtherTerm][COMMA] = 83;
        mp[OtherTerm][DO] = 83;
        mp[OtherTerm][THEN] = 83;
        mp[OtherTerm][SEMI] = 83;
        mp[OtherTerm][ENDWH] = 83;
        mp[OtherTerm][ELSE] = 83;
        mp[OtherTerm][FI] = 83;
        mp[OtherTerm][END] = 83;
        mp[OtherTerm][PLUS] = 84;
        mp[OtherTerm][MINUS] = 84;
        mp[Term][LPAREN] = 85;
        mp[Term][INTC_VAL] = 85;
        mp[Term][ID] = 85;
        mp[OtherFactor][PLUS] = 86;
        mp[OtherFactor][MINUS] = 86;
        mp[OtherFactor][RMIDPAREN] = 86;
        mp[OtherFactor][RPAREN] = 86;
        mp[OtherFactor][LT] = 86;
        mp[OtherFactor][EQ] = 86;
        mp[OtherFactor][COMMA] = 86;
        mp[OtherFactor][DO] = 86;
        mp[OtherFactor][THEN] = 86;
        mp[OtherFactor][SEMI] = 86;
        mp[OtherFactor][ENDWH] = 86;
        mp[OtherFactor][ELSE] = 86;
        mp[OtherFactor][FI] = 86;
        mp[OtherFactor][END] = 86;
        mp[OtherFactor][TIMES] = 87;
        mp[OtherFactor][DIVIDE] = 87;
        mp[Factor][LPAREN] = 88;
        mp[Factor][INTC_VAL] = 89;
        mp[Factor][CHAR_VAL] = 90;
        mp[Factor][ID] = 91;
        mp[Variable][ID] = 92;
        mp[VariMore][ASSIGN] = 93;
        mp[VariMore][TIMES] = 93;
        mp[VariMore][DIVIDE] = 93;
        mp[VariMore][PLUS] = 93;
        mp[VariMore][MINUS] = 93;
        mp[VariMore][RMIDPAREN] = 93;
        mp[VariMore][RPAREN] = 93;
        mp[VariMore][LT] = 93;
        mp[VariMore][EQ] = 93;
        mp[VariMore][COMMA] = 93;
        mp[VariMore][DO] = 93;
        mp[VariMore][THEN] = 93;
        mp[VariMore][SEMI] = 93;
        mp[VariMore][ENDWH] = 93;
        mp[VariMore][ELSE] = 93;
        mp[VariMore][FI] = 93;
        mp[VariMore][END] = 93;
        mp[VariMore][LMIDPAREN] = 94;
        mp[VariMore][DOT] = 95;
        mp[FieldVar][ID] = 96;
        mp[FieldVarMore][ASSIGN] = 97;
        mp[FieldVarMore][TIMES] = 97;
        mp[FieldVarMore][DIVIDE] = 97;
        mp[FieldVarMore][PLUS] = 97;
        mp[FieldVarMore][MINUS] = 97;
        mp[FieldVarMore][RMIDPAREN] = 97;
        mp[FieldVarMore][RPAREN] = 97;
        mp[FieldVarMore][LT] = 97;
        mp[FieldVarMore][EQ] = 97;
        mp[FieldVarMore][COMMA] = 97;
        mp[FieldVarMore][DO] = 97;
        mp[FieldVarMore][THEN] = 97;
        mp[FieldVarMore][SEMI] = 97;
        mp[FieldVarMore][ENDWH] = 97;
        mp[FieldVarMore][ELSE] = 97;
        mp[FieldVarMore][FI] = 97;
        mp[FieldVarMore][END] = 97;
        mp[FieldVarMore][LMIDPAREN] = 98;
        mp[CmpOp][LT] = 99;
        mp[CmpOp][EQ] = 100;
        mp[AddOp][PLUS] = 101;
        mp[AddOp][MINUS] = 102;
        mp[MultOp][TIMES] = 103;
        mp[MultOp][DIVIDE] = 104;
    }
};




#endif // _parserLL1_h
