#!/bin/python
from bs4 import BeautifulSoup as BS
import re

###################################################
#### declarations
soup = BS(open('pre.html'),"lxml")

#列表
expression = []
predict = []
terminal = []

# output file
output = open('parser.cpp', 'w')
header = open('parser.h', 'w')
headerbak = open('terminals', 'r')

nTerminal = open('nTerminal','w')


lines = headerbak.readlines()
header.writelines(lines)
log = open('log', 'w')

#### initializations
output.write('''#include "parser.h"
#include <iostream>
using namespace std;\n\n''')

table = soup.table

for tr in table.find_all('tr'):
    expr = re.sub(r'\s+', ' ', tr.find('td', class_='expression').getText()).split(' ')

    #print(expr)
    tmp = []
    tmp.append(expr[0])

    nTerminal.write(expr[0] + '\n')
    
    tmp.append(expr[1:])
    expression.append(tmp)
    tmp = []
    tmp.append(re.sub(r'\s+', ' ', tr.find('td', class_='predict').getText()).split(','))
    #predict.append(tmp.append(tr.find('td', class_='predict').getText().strip(' ').split(',')))
    predict.append(tmp)

for tok in (open('terminals', 'r')).readlines():
    terminal.append(tok.strip('\n'))
print('expression: ' + str(len(expression)))
###################################################

## elimate dulpicated expression
cache = []
count = len(expression)
i = 0
while i < count:
    if (expression[i])[0] not in cache:
        cache.append((expression[i])[0])
        i = i + 1
    else:
        expression[i-1].append((expression[i])[1])
        predict[i-1].append(predict[i][0])
        del(expression[i])
        del(predict[i])
        count = count - 1

#print(expression)
#print(predict)
## write expression and predict to log
log.write('##################  expression  ##################\n')
for line in expression:
    log.write(str(line) + '\n')
    print(line)
log.write('##################  predict  ##################\n')
for line in predict:
    log.write(str(line) + '\n')
    print(line)
#################################

## append method declarations to parser.h
def add2header():
    for exp in expression:
        header.write('\n    STnode * ' + exp[0] + '();')
    header.write('\n    bool match(LexType lex);')
    header.write('\n};\n')
    header.write('#endif')

#experssion[index]
    
def branch(index):
    indent = "  "
    output.write('\n' + indent + 'if(cur_token->getLex() == ')
    exp = expression[index]
    prd = predict[index]
    for i in range(1, len(exp) - 1):
        for j in prd[i-1]:
            if j == prd[i-1][-1]:
                output.write(j + ')\n' + indent + '{')
            else:
                output.write(j + ' || cur_token->getLex() == ')
        indent = indent + '  '
        for tok in exp[i][1:]:
            if tok not in terminal:
                if tok.strip() == 'ε':
                    output.write('\n' + indent + 'return nullptr;')
                else:
                    output.write('\n' + indent + tok + '();')
            else:
                output.write('\n' + indent + 'match(' + tok + ');')
        indent = indent[:len(indent)-2]
        output.write('\n' + indent + '}' + '\n' + indent + 'else if(cur_token->getLex() == ')
    for j in prd[-1]:
        if j == prd[-1][-1]:
            output.write(j + ')\n' + indent + '{')
        else:
            output.write(j + ' || cur_token->getLex() == ')
    indent = indent + '  '
    for tok in exp[-1][1:]:
        if tok not in terminal:
            if tok.strip() == 'ε':
                output.write('\n' + indent + 'return nullptr;')
            else:
                output.write('\n' + indent + tok + '();')
        else:
            output.write('\n' + indent + 'match(' + tok + ');')
    indent = indent[:len(indent)-2]
    output.write('\n' + indent + '}')



# expression[index]

def constructFunc(index):
    output.write("\nSTnode * Parser::" + (expression[index])[0] + "()\n{")

    indent = "  "

    if(len(expression[index]) > 2):
        branch(index);
    else:
        for tok in (expression[index][1])[1:]:
            if tok not in terminal:
                if tok.strip() == 'ε':
                    output.write('\n' + indent + 'return nullptr;')
                else:
                    output.write('\n' + indent + tok + '();')
            else:
                output.write('\n' + indent + 'match(' + tok + ');')

    output.write('\n' + indent + 'return nullptr;')
    output.write("\n}\n")

def add_match_method():
    output.write('''
            bool Parser::match(LexType lex)
            {
                if(cur_token->getLex() == lex)
                {
                    //cout<<cur_token->getSem()<<endl;
                    pre_token = cur_token;
                    cur_token = cur_token->next;
                    return true;
                }
                else
                {
                    cout<<"line "<<cur_token->getLine()<<" : unexpected token "<<cur_token->getLexName()<<" : "<<cur_token->getSem()<<endl;
                    this->state = false;
                    return false;
                }
            }
            ''')
#############################################
## action
add2header()
for i in range(len(expression)):
    constructFunc(i)
add_match_method();

#for i in expression:
    #print(i)


#for i in predict:
    #print(i)
