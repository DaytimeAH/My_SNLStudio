#!/usr/bin/env python  
# -*- coding:utf-8 -*-  

import re
import os  
import os.path
import sys

def go(file):
	output = open(file,'w')
	input_ = open('../../outputTree/Myout','r')
	#input = open('test.txt','r')

	liness = input_.readlines()

	numlst= []
	stalst =[]

	net = 0
	for lines in liness:
		ll = len(lines)
		num = lines.find(":")
	#	print(str(num))
	#	input()
		stalst.append(num)
		#print(lines[0:num])
		numlst.append(lines[0:num])

		#print(numlst)
		#print(stalst)
		#input()

	#numlst.append()
	for i in range(len(numlst) - 1):
		j = int(numlst[i])
		ne = int(numlst[i+1])

		#print(ne)

		if j < ne:
			output.write("{" + '\n')
			#print(liness[i][stalst[i]+1:])
			#input()
			output.write("\"name\" : " +"\""+ liness[i][stalst[i]+1:].strip() + "\",\n")
			output.write("\"children\" : [\n")
		elif j == ne:
			output.write("{\n\"name\" : "  + "\"" + liness[i][stalst[i]+1:].strip() + "\"\n},\n")
		elif j > ne:
			output.write("{\"name\" : " + "\"" + liness[i][stalst[i]+1:].strip() + "\"\n}\n]\n}\n")
			for tt in range(int(ne),int(j)-1):
				output.write("]\n}")
			if ne != 1:
				output.write(",")
	output.close()

if __name__ == "__main__":
	go(sys.argv[1])




'''
pre = 0
for lines in input.readlines():
	#print(len(lines))
	ll = len(lines)
	i = 0
	while lines[i] == ' ':
		i +=1
	i /= 2

	if pre < i:
		pre = i
		output.write("{" + '\n')
		output.write("\"name\" : " +"\""+ lines.strip() + "\",\n")
		output.write("\"children\" : [\n{")
	elif pre == i:
		output.write("\"name : \"" + "\"" + lines.strip() + "\n},\n{")
	elif pre > i:
		pre = i
		output.write("]\n},\n{\n")
		output.write("\"name\" : " +"\""+ lines.strip() + "\",\n")
		output.write("\"children\" : [\n{")

'''







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



