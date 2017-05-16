#include <iostream>
#include "include/Python.h"
#include "scanner.h"
#include "parse.h"
#include "parserLL1.h"
#include "ReserchLR1.h"
//#include "parser.h"
using namespace std;


Token * lexsolve(string filename)
{
    Lexer * lex = Lexer::getLexer(filename.c_str());
	cout<<"Starting lexical analysis: "<<endl;
    Token * head = lex->getTokenList();
    lex->printTokenList(head);
    cout<<"ok\n";
    return head;
}

void parsersolve(Token * head)
{
    cout << "Starting Recursive analysis: " << endl;
    Parser * parser = Parser::getParser(head);
    parser->Program();

    if(parser->state)
        cout<<"Recursive: No error occured.\n";
    else cout<<"Recursive: Error occured.\n";
}

void parserLLsolve(Token * head)
{
    cout << "Staring LL1 analysis: result save to Myout.txt" << endl;
    ParserLL * parser = ParserLL::getParser(head);
    parser->parse();
    if(parser->state)
        cout<<"LL1: No error occured.\n";
    else cout<<"LL1: Error occured.\n";
}


void parserLRsolve(Token * head, string file)
{
    cout << "Staring LR1 analysis: result save to wz.json" << endl;
    ParserLR1 * parser = ParserLR1::getParser(head,file);
    parser->parse();
    if(parser->state)
        cout<<"LR1: No error occured.\n";
    else cout<<"LR1: Error occured.\n";
}

bool use_Py(string file)
{
	char c[] = "G:/DarknessH/Python/Python35-32";
	const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);
	Py_SetPythonHome(wc);
    Py_Initialize();
    if (!Py_IsInitialized())
    {
        return 0;
    }
	PyObject *pModule = NULL;
	PyObject *pFunc = NULL;
	pModule = PyImport_ImportModule("help");
	pFunc = PyObject_GetAttrString(pModule, "go");
	PyObject *pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", file.c_str()));
	PyEval_CallObject(pFunc, pArgs);
	Py_Finalize();
    return 1;
}


int main(int argv, char * arg[])
{
    string input,output;
    int op = 0;
    if(argv == 1)
    {
        input = "C://Users//DarknessH//Desktop//myIntelliStudio//studio//MySNL//MySNL//error.txt";
        op = 3;
        output = "Treedata.json";
    }
    else
    {
        op = atoi(arg[1]);
        input = string(arg[2]);
        output = string(arg[3]);
        cout << op << ' ' << input << ' ' << output << endl;
    }

    //词法分析
    Token *head = lexsolve(input);
    switch(op)
    {
    case 1:
        //语法分析 递归向下
        parsersolve(head);
        cout<<"ok Recursive\n\n";
        break;
    case 2:
        //语法分析 LL(1)
        parserLLsolve(head);
        use_Py(output);
        cout << "ok LL1\n\n";
        break;
    case 3:
        //语法分析 LR(1)
        parserLRsolve(head,output);
        cout << "ok LR1\n\n";
        break;
    default:
        cout <<"input error\n\n";
        break;

    }

    return 0;
}





//    FILE * file = fopen("path.txt","r");
/*

void readtxt(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    //assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();
}
*/
