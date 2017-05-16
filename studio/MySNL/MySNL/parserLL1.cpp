#include <map>
#include <stack>
#include <fstream>
#include <cstring>
#include <iostream>
#include "parserLL1.h"

using namespace std;

map<int, string> Tnode =
{
    {Program, "Program"},
    {ProgramHead, "ProgramHead"},
    {ProgramName, "ProgramName"},
    {DeclarePart, "DeclarePart"},
    {TypeDecPart, "TypeDecPart"},
    {TypeDec, "TypeDec"},
    {TypeDecList, "TypeDecList"},
    {TypeDecMore, "TypeDecMore"},
    {TypeId, "TypeId"},
    {TypeDef, "TypeDef"},
    {BaseType, "BaseType"},
    {StructureType, "StructureType"},
    {ArrayType, "ArrayType"},
    {Low, "Low"},
    {Top, "Top"},
    {RecType, "RecType"},
    {FieldDecList, "FieldDecList"},
    {FieldDecMore, "FieldDecMore"},
    {IdList, "IdList"},
    {IdMore, "IdMore"},
    {VarDecPart, "VarDecPart"},
    {VarDec, "VarDec"},
    {VarDecList, "VarDecList"},
    {VarDecMore, "VarDecMore"},
    {VarIdList, "VarIdList"},
    {VarIdMore, "VarIdMore"},
    {ProcDecPart, "ProcDecPart"},
    {ProcDec, "ProcDec"},
    {ProcDecMore, "ProcDecMore"},
    {ProcName, "ProcName"},
    {ParamList, "ParamList"},
    {ParamDecList, "ParamDecList"},
    {ParamMore, "ParamMore"},
    {Param, "Param"},
    {FormList, "FormList"},
    {FidMore, "FidMore"},
    {ProcBody, "ProcBody"},
    {ProgramBody, "ProgramBody"},
    {StmList, "StmList"},
    {StmMore, "StmMore"},
    {Stm, "Stm"},
    {AssCall, "AssCall"},
    {AssignmentRest, "AssignmentRest"},
    {ConditionalStm, "ConditionalStm"},
    {LoopStm, "LoopStm"},
    {InputStm, "InputStm"},
    {Invar, "Invar"},
    {OutputStm, "OutputStm"},
    {ReturnStm, "ReturnStm"},
    {CallStmRest, "CallStmRest"},
    {ActParamList, "ActParamList"},
    {ActParamMore, "ActParamMore"},
    {RelExp, "RelExp"},
    {OtherRelE, "OtherRelE"},
    {Exp, "Exp"},
    {OtherTerm, "OtherTerm"},
    {Term, "Term"},
    {OtherFactor, "OtherFactor"},
    {Factor, "Factor"},
    {Variable, "Variable"},
    {VariMore, "VariMore"},
    {FieldVar, "FieldVar"},
    {FieldVarMore, "FieldVarMore"},
    {CmpOp, "CmpOp"},
    {AddOp, "AddOp"},
    {MultOp, "MultOp"},
    {HHH, "HHH"},
    {PROGRAM, "PROGRAM"},
    {TYPE, "TYPE"},
    {VAR, "VAR"},
    {PROCEDURE, "PROCEDURE"},
    {BEGIN, "BEGIN"},
    {END, "END"},
    {ARRAY, "ARRAY"},
    {OF, "OF"},
    {RECORD, "RECORD"},
    {IF, "IF"},
    {THEN, "THEN"},
    {ELSE, "ELSE"},
    {FI, "FI"},
    {WHILE, "WHILE"},
    {DO, "DO"},
    {ENDWH, "ENDWH"},
    {READ, "READ"},
    {WRITE, "WRITE"},
    {RETURN, "RETURN"},
    {INTEGER, "INTEGER"},
    {CHAR, "CHAR"},
    {INTEGER_T, "INTEGER_T"},
    {CHAR_T, "CHAR_T"},
    {ID, "ID"},
    {ASSIGN, "ASSIGN"},
    {EQ, "EQ"},
    {LT, "LT"},
    {PLUS, "PLUS"},
    {MINUS, "MINUS"},
    {TIMES, "TIMES"},
    {DIVIDE, "DIVIDE"},
    {LPAREN, "LPAREN"},
    {RPAREN, "RPAREN"},
    {DOT, "DOT"},
    {COLON, "COLON"},
    {SEMI, "SEMI"},
    {COMMA, "COMMA"},
    {LMIDPAREN, "LMIDPAREN"},
    {RMIDPAREN, "RMIDPAREN"},
    {UNDERRANGE, "UNDERRANGE"},
    {ENDFILE, "ENDFILE"},
    {ERROR, "ERROR"},
    {INTC_VAL, "INTC_VAL"},
    {CHAR_VAL, "CHAR_VAL"},

};


bool  ParserLL::match(LexType lex)
{
    if(cur_token->getLex() == lex)
    {
        pre_token = cur_token;
        cur_token = cur_token->next;
        return true;
    }
    else
    {
        cout << "line " << cur_token->getLine() << ": unexpected token ";
        cout << cur_token->getLexName() << " sem: " << cur_token->getSem() << endl;
        this->state = false;
        return false;
    }
}
void ParserLL::parse()
{

    stack<int> sta;
    stack<int> levers;

    sta.push(-1);
    sta.push(Program);

    levers.push(-1);
    levers.push(0);
    levers.push(1);

    while(cur_token != NULL)
    {
        int pre = sta.top();
        int lev = levers.top();

        LexType now_lex = cur_token->getLex();

        if(pre == HHH)
        {
            sta.pop();
            levers.pop();
            continue;
        }
        //printf("pre = %d %d %d\n",pre,cur_token->getLex(),cur_token->getLine());
        if(pre >= 100)
        {
            int expression = mp[pre][now_lex];

            //printf("expression = %d\n",expression);
            if(expression < 0)
            {
                output << "line " << cur_token->getLine() << ": unexpected token ";
				output << cur_token->getLexName() << " sem: " << cur_token->getSem() << '\n';
                cout << "line " << cur_token->getLine() << ": unexpected token ";
				cout << cur_token->getLexName() << " sem: " << cur_token->getSem() << '\n';
                state = false;
                break;
            }
            sta.pop();
            levers.pop();
			//cout << lev << endl;
            output << lev << ":";
			cout << lev << ":";
            for(int i = 0; i < lev*2; i++)
                output << " ", cout << " ";
            output << Tnode[pre] << '\n';
            cout << Tnode[pre] << '\n';

            for(int i = 0; i < exnode[expression].len; i++)
            {
                sta.push(exnode[expression].lst[i]);
                levers.push(lev + 1);
            }
        }
        else
        {
            if(match((LexType)pre))
            {
                sta.pop();
                levers.pop();
                //printf("%d ",lev);
                output << lev << ":";
                for(int i = 0; i < lev * 2; i++)
                    output << " ", cout << " ";
                output << Tnode[pre] << " " << pre_token->getSem() << '\n';
                cout << Tnode[pre] << " " << pre_token->getSem() << '\n';
            }
            else
            {
                output << "line " << cur_token->getLine() << ": unexpected token ";
                output << cur_token->getLexName() << " sem: " << cur_token->getSem() << '\n';
                state = false;
                break;
            }
        }
    }
    if(sta.top() != -1)
    {
        state = false;
        cout << "1:  fuck" << endl;
    }
    else output << "1:  ok LL1\n";
	output.close();
}

