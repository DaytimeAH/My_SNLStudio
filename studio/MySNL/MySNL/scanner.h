#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <map>
#include <cstring>
#include <fstream>

using namespace std;


enum LexType
{
    /* reserved words */
    PROGRAM  = 1,TYPE,VAR,PROCEDURE,
    BEGIN,    END,    ARRAY,  OF,
    RECORD,   IF,     THEN,   ELSE,
    FI,       WHILE,  DO,     ENDWH,
    READ,     WRITE,  RETURN,INTEGER, CHAR,

     //types, just a symbol of type "name", no actual sematic infomation
    INTEGER_T, CHAR_T,

    // INTC_VAL == INTC CHARC = CHAR_VAL
    ID,  INTC_VAL, CHAR_VAL,
    /*specical*/

    ASSIGN, EQ,     LT,     PLUS, MINUS,
    TIMES,  DIVIDE, LPAREN, RPAREN,
    DOT,    COLON,  SEMI,   COMMA,
    LMIDPAREN, RMIDPAREN, UNDERRANGE,
	RRR,

   //error endfile
    ENDFILE = 0, ERROR = -1,

};

extern map<LexType, string> lexName;

extern map<string, LexType> reservedWords;

// Token

class Token
{
public:
    Token(int line, LexType lex, string sem)
    {
        this->line = line;
        this->lex = lex;
        this->sem = sem;
        next = NULL;
    }
    int getLine()
    {
        return line;
    }
    string getLexName()
    {
        return lexName[lex];
    }
    LexType getLex()
    {
        return lex;
    }
    string getSem()
    {
        return sem;
    }
    Token * next;
private:
    int line;
    LexType lex;
    string sem;
};

// Lex Token

class Lexer
{
public:
    static Lexer * getLexer(const char * filename)
    {
        return (new Lexer(filename));
    }
    ~Lexer()
    {
        code.close();
    }
    Token * getTokenList();
    void printTokenList(Token * head);

private:
    Lexer(const char * filename) : lineRec(0), idBuff(""), intBuff(0)
    {
        code.open(filename);
    }
    ifstream code;
    int lineRec;
    string idBuff;
    double intBuff;
    Token * reversedLookup(string str);
    bool isssep(char c);
    Token * ssep(char c);
};



#endif // SCANNER_H_INCLUDED
