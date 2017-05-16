#!/usr/bin/env python  
# -*- coding:utf-8 -*-  

import re
import os  
import os.path

output = open('output.txt','w')
input = open('input.txt','r')


strTest = strTxt.decode('utf-8', 'ignore')
strTxt = "C:\Users\win\Desktop"
""" 获得字典
regex = re.compile(r'\w*\w');

for str in input.readlines():
	#print(str)
	lst = regex.findall(str)

	for i in range(len(lst)):
		#print(lst[i])
		lst[i] += ' , "' + lst[i] + 'K"'

		output.write('{'+lst[i] + '},\n')
"""

os.walk(strTxt)


