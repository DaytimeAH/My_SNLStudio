#include "ReserchLR1.h"
using namespace std;
map<LexType, string> lexName1 =
{
    {PROGRAM, "PROGRAM"},   {TYPE, "TYPE"}, {VAR, "VAR"},       {PROCEDURE, "PROCEDURE"},
    {BEGIN, "BEGIN"},       {END, "END"},   {ARRAY, "ARRAY"},   {OF, "OF"},
    {RECORD, "RECORD"},     {IF, "IF"},     {THEN, "THEN"},     {ELSE, "ELSE"},
    {FI, "FI"},             {WHILE, "WHILE"},{DO, "DO"},        {ENDWH, "ENDWH"},
    {READ, "READ"},         {WRITE, "WRITE"},{RETURN, "RETURN"},{INTEGER, "INTEGER"},
    {CHAR, "CHAR"}, {INTEGER_T, "INTEGER_T"},{CHAR_T, "CHAR_T"},{ID, "ID"},
    {INTC_VAL, "INTC_VAL"},{CHAR_VAL, "CHAR_VAL"},{ASSIGN, "ASSIGN"},{EQ, "EQ"},
    {LT, "LT"},     {PLUS, "PLUS"},         {MINUS, "MINUS"},   {TIMES, "TIMES"},
    {DIVIDE, "DIVIDE"}, {LPAREN, "LPAREN"}, {RPAREN, "RPAREN"}, {DOT, "DOT"},
    {COLON, "COLON"},   {SEMI, "SEMI"},     {COMMA, "COMMA"},   {LMIDPAREN, "LMIDPAREN"},
    {RMIDPAREN, "RMIDPAREN"},   {UNDERRANGE, "UNDERRANGE"},       {ENDFILE, "ENDFILE"},
    {ERROR, "ERROR"},{RRR,"#"}
};

vector<string> ParserLR1::split(string& str, const char* c)
{
    char *cstr, *p;
    vector<string> res;
    cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());
    p = strtok(cstr, c);
    while (p != NULL)
    {
        res.push_back(p);
        p = strtok(NULL, c);
    }
    return res;
}

void ParserLR1::readLR1()
{
    int i, j;
    ifstream ifs;
    ifs.open("C:/Users/DarknessH/Desktop/myIntelliStudio/studio/MySNL/wz/a.txt");
    int k;
    for (i = 1; i <= closure_num; i++)
    {
        for (j = 1; j <= vt_num; j++)
        {
            ifs >> k;
            lr1action[i][j] = k;
        }
        for (j = 1; j <= vn_num; j++)
        {
            ifs >> k;
            lr1goto[i][j] = k;
        }
    }

    ifs.close();
    ifs.open("C:/Users/DarknessH/Desktop/myIntelliStudio/studio/MySNL/wz/vn_map.txt");
    string str;
    int vnn = 0;
    while (ifs>>str)
    {
        if (vn_map[str] == 0)
        {
            vn_map[str] = ++vnn;
            vn[vnn] = str;
        }
    }
    ifs.close();
    ifs.open("C:/Users/DarknessH/Desktop/myIntelliStudio/studio/MySNL/wz/vt_map.txt");
    int vtn = 0;
    while (ifs >> str)
    {
        if (vt_map[str] == 0)
        {
            vt_map[str] = vtn;
            vt[vtn] = str;
            vtn++;
        }
    }
    ifs.close();
//    for (int i = 1; i <= vn_num; i++)
//    {
//        cout <<i<<" "<< vn[i] << endl;
//    }
//    for (int i = 1; i <= vt_num; i++)
//    {
//        cout << i << " " << vt[i] << endl;
//    }
    ifs.open("C:/Users/DarknessH/Desktop/myIntelliStudio/studio/MySNL/wz/to_wz.txt");
    i = 1;
    while (getline(ifs,str))
    {
        if (str == "@")
            break;
        vector<string> strnext = split(str, " ");
        g[i].vn = strnext[0];
        for (j = 1; j < strnext.size(); j++)
            g[i].s.push_back(strnext[j]);
        i++;
    }
    ifs.close();
    g[0].vn = "$";
    g[0].s.push_back(g[1].vn);
//    for (j = 0; j < i; j++)
//    {
//        cout << j << ":" << g[j].vn << "->";
//        for (int m = 0; m < g[j].s.size(); m++)
//            cout << g[j].s[m] << " ";
//        cout << endl;
//    }
}


int ParserLR1::GotoLr1(int grammar)
{
    int i;
    statues newcondition;
    tree* t;
    t = new tree();
    t->father = g[grammar].vn;
    t->son.clear();
    statues lastcondition;
    int k;
    if (g[grammar].s[0] == "@")
    {
        lastcondition = condition.top();
        t->line = lastcondition.next->line;
        newcondition.next = t;
        k = lr1goto[lastcondition.c][vn_map[newcondition.next->father]];
        if (k == -999)
            return 0;
        if (k<0)
        {
           // cout<<"114:"<<"goto:"<<k;
            newcondition.c = -k;
            condition.push(newcondition);
            symbol.push(newcondition.next->father);
            return 3;
        }
        else
        {
          //  cout<<"120:"<<"goto:"<<k;
            return -1;
        }
    }
    int max = 0;
    for (i = 0; i < g[grammar].s.size(); i++)
    {
        symbol.pop();
        statues nowcondition = condition.top();
        if (max < nowcondition.next->line)
            max = nowcondition.next->line;
        t->son.push_back(nowcondition.next);
        condition.pop();
    }
    max++;
    t->line = max;
    newcondition.next = t;
    lastcondition = condition.top();
    k = lr1goto[lastcondition.c][vn_map[newcondition.next->father]];
    if (k == -999)
        return 0;
    if (k<0)
    {
       // cout<<"137:"<<"goto:"<<k;
        newcondition.c = -k;
        condition.push(newcondition);
        symbol.push(newcondition.next->father);
        return 3;
    }
    else
    {
       // cout<<"143:"<<"goto:"<<k;
        return -1;
    }

}


int ParserLR1::reserchLR1(string next,string value,int line)
{
    statues lastcondition;
    statues nextcondition(next,value,line);
    lastcondition.c = condition.top().c;
    lastcondition.next = condition.top().next;
    int k;
    if (next == "#")
    {
        if (symbol.size() == 2 && symbol.top() == "Program")
            return 2;
    }
    if (vt_map[next])
    {
        cout<<"lastcondition:"<<lastcondition.c<<endl;
        cout << vt_map[next] << '/' << lr1action[abs(lastcondition.c)][vt_map[next]] <<endl;
        k = lr1action[lastcondition.c][vt_map[next]];
        if (k == -999)
            return 0;
        if (k < 0)
        {
            nextcondition.c = -k;
            condition.push(nextcondition);
            symbol.push(next);
    //        cout<<"169:"<<"action:"<<k<<endl;
            return 1;
        }
        else
        {
            return GotoLr1(k);
        }
    }
    else
    {
        cout<<"182:error vn"<<endl;
        return 0;
    }
}

void ParserLR1::readTokens()
{
    Token *head = current;
    int i=0;
    while (head!=NULL)
    {
        input.push_back(Token(head->getLine(), head->getLex(), head->getSem()));
        i = head->getLine();
        head = head->next;
    }

    input.push_back(Token(i,RRR,"#"));
}

void ParserLR1::printftree(int i, tree* root)
{
    int j;
    cout << root->line << ":";
    for (j = 1; j <= 2 * i; j++)
        cout << " ";
    cout << root->father;
    if (vt_map[root->father])
    {
        cout<<" "<<root->son[0]->father<<endl;
    }
    else
    {
        cout<<endl;
        i = i + 1;
        for (j = 0; j < root->son.size(); j++)
        {
            printftree(i, root->son[j]);
        }
    }
}
void ParserLR1::printjason(tree* root)
{
    int i;
    ofs<<"{"<<endl;
    ofs<<"\"name\""<<":"<<"\""<<root->father<<"\"";
    if (root->son.size()>=1)
    {
        ofs<<","<<endl;
        ofs<<"\"children\":"<<endl;
        ofs<<"["<<endl;
        for (i=0; i<root->son.size(); i++)
        {
            printjason(root->son[i]);
            if (i<root->son.size()-1)
            {
                ofs<<","<<endl;
            }
            else
            {
                ofs<<endl;
            }
        }
        ofs<<"]"<<endl;
        ofs<<"}"<<endl;
    }
    else
    {
        ofs<<"}"<<endl;
    }
}

void ParserLR1::analysisLr1()
{
    int i,statu;
    i = 0;
    string str;
    statues firststatues;
    statues lastcondition;
    firststatues.c = 1;
    tree* t;
    t = new tree();
    t->father = "#";
    t->son.clear();
    cout<<t->father<<endl;
    t->line = 1;
    firststatues.next = t;
    condition.push(firststatues);
    symbol.push("#");
    int xx;
    string value;
    int line;
    while (i<input.size())
    {
        cout<<"input["<<i<<"] = "<< input[i].getLex()<<endl;
        str = lexName1[input[i].getLex()];
        cout<<"str:"<<str<<endl;
        value = input[i].getSem();
        line = 1;
        statu = reserchLR1(str,value,line);
        if (!statu)
        {
            lastcondition = condition.top();
            state = 0;
            cout << "inerror\n";
            cout << "line " << input[i].getLine() << ": unexpected token " << input[i].getLexName() << " sem: " << input[i].getSem() << endl;
            //     printftree(1, lastcondition.next, 1);
            break;
        }
        if (statu == 1)
        {
            i++;
            cout<<i<<endl;
        }
        if (statu == 2)
        {
            lastcondition = condition.top();
            printftree(1, lastcondition.next);
            printf("acc\n");
            break;
        }
        if (statu == 3)
        {
            continue;
        }
        if (statu == -1)
        {
            state = 0;
            //  printftree(1, lastcondition.next, 1);
            cout<<"GOTO error"<<endl;
            cout << "line " << input[i].getLine() << ": unexpected token " << input[i].getLexName() << " sem: " << input[i].getSem() << endl;
        }
    }
    cout<<"over"<<endl;
}


int ParserLR1::parse()
{
    readLR1();
    readTokens();
    analysisLr1();
    ofstream ofs;
    printjason(condition.top().next);
    ofs.close();
    return 0;
}

