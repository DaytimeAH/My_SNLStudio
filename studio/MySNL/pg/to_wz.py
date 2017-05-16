#!/bin/python
from bs4 import BeautifulSoup as BS
import re


soup = BS(open('pre.html'))
output = open('to_wz_pre.txt','w')
expression = []
predict = []
terminal = []
nTerminal = []
iid = []
cnt = 0
table = soup.table
ss = ''

for tr in table.find_all('tr'):
    expr = re.sub(r'\s+',' ',tr.find('td',class_='expression').getText()).split(' ')

    ################ expression ##############
    tmp = []
    tmp.append(expr[0])
    tmp.append(expr[1:])
    expression.append(tmp)

    if ss != expr[0]:
        #MynTerminal.write(expr[0].strip(' ')+ '\n')
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
"""
exlen = len(expression)
for i in range(exlen):
	expression[i][1][0] = ' '
	if expression[i][1][1] == 'ε':
		expression[i][1][1] = '@'

for ex in range(exlen):
	it = expression[ex]
	ll = len(it)
	output.write(str(it[0]) + ' ')

	ll = len(it[1])
	for j in range(ll):
		if j == ll - 1:
			output.write(str(it[1][j]) + '\n')
		else:
			if j == 0:
				continue
			output.write(str(it[1][j]) + ' ')

"""
i = 0
count = len(expression)
cache = []
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


len_pre = len(predict)

#print(str(len(expression)) + ' ' +  str(len_pre))

for i in range(len_pre):
    output.write(str(expression[i][0]))
    len_1 = len(predict[i])
    for j in range(len_1):
        len_2 = len(predict[i][j])
        for k in range(len_2):
            output.write(' ' + str(predict[i][j][k]))
    output.write('\n')
