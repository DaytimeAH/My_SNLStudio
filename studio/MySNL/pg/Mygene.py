#!/bin/python
from bs4 import BeautifulSoup as BS 
import re

soup = BS(open('pre.html'),"lxml")

expression = []
predict = []
terminal = []
nTerminal = []

cnt = 0
myID= []
iid = []

table = soup.table

ss = ''
MynTerminal = open('nTerminals','w')


for tr in table.find_all('tr'):
    expr = re.sub(r'\s+',' ',tr.find('td',class_='expression').getText()).split(' ')

    ################ expression ##############
    tmp = []
    tmp.append(expr[0])
    tmp.append(expr[1:])
    expression.append(tmp)

    if ss != expr[0]:
        MynTerminal.write(expr[0].strip(' ')+ '\n')
        ss = expr[0]
        nTerminal.append(expr[0].strip(' '))


    ################ predict ##################
    tmp = []
    tmp.append(re.sub(r'\s+',' ',tr.find('td',class_ = 'predict').getText()).split(','))
    predict.append(tmp)

    myID = []
    myID.append(cnt)
    iid.append(myID)
    cnt += 1;

for tok in (open('terminals','r')).readlines():
    terminal.append(tok.strip('\n'))


cache = []
count = len(expression)
i = 0

while i < count:
    if (expression[i])[0] not in cache:
        cache.append(expression[i][0])
        i += 1
    else:
        expression[i-1].append(expression[i][1])
        predict[i-1].append(predict[i][0])
        iid[i-1].append(iid[i][0])

        del expression[i]
        del predict[i]
        del iid[i]
        count -= 1

#print(count)
#print(iid)

count = len(nTerminal)
myParseH = open('myParse.h','w')

myParseH.write('''enum nTerminal
{
      ''')


for i in range(count):
    myParseH.write(nTerminal[i] + ',')
    if i % 4 == 0:
        myParseH.write('\n')
        myParseH.write('''      ''')
myParseH.write('\n' + '}' + '\n')


########################## terminal ############################
"""
count = len(terminal)

myParseH.write('''enum Terminal
{
      ''')


for i in range(count):
    myParseH.write(terminal[i] + ',')
    if i % 4 == 0:
        myParseH.write('\n')
        myParseH.write('''      ''')
myParseH.write('\n' + '}' + '\n')

"""
###########################  exnode #######################

myParseH.write('''
struct exNode
{
    int len = 0;
    int lst[10];
} exnode[''')
count = len(nTerminal)
myParseH.write(str(count))
myParseH.write("];\n\n")

for i in range(count):
    lst = expression[i]
    j = 1
    ll = len(lst)
    while j < ll:
        sonlst= lst[j]

        sonll = len(sonlst)
        lastid = iid[i][j-1]

        myParseH.write("exnode[" + str(lastid) + '].len = ' + str(sonll - 1) + ';\n')

        for t in range(1,sonll):
            #print('l')
            if sonlst[t].strip() != 'ε' :
                myParseH.write(("exnode[" + str(lastid) + '].lst[' + str(sonll - 1 -t) + '] = ' + sonlst[t] + ';\n'))
            else:
                myParseH.write(("exnode[" + str(lastid) + '].lst[' + str(sonll - 1 -t) + '] = ' + "HHH"+ ';\n'))

        j += 1



###################### map #########################

myParseH.write('\n')
myParseH.write('int mp[' + str(len(nTerminal)) + ']['+str(len(terminal)) + '];\n')
#
#l1 = len(nTerminal)
#l2 = len(terminal)
#
count = len(nTerminal)
for i in range(count):
    lst = expression[i]
    j = 1
    ll = len(lst)
    while j < ll:
        sonlst = predict[i][j - 1]
        sonll = len(sonlst)
        #print(sonlst)
        for t in range(sonll):
            myParseH.write('mp[' + expression[i][0] + '][')
            myParseH.write(sonlst[t] + '] = ' + str(iid[i][j-1]) + ';\n' )
        j += 1










































