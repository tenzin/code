#!/usr/bin/python
# -*- coding: utf-8 -*-

# Python program by Tenzin
# 11 March 2009

import os, sys

char_dict = {"a" : "ɐ", "b" : "q", "c" : "ɔ", "d" : "p", 
	    "e" : "ǝ", "f" : "ɟ", "g" : "ƃ", "h" : "ɥ", 
	    "i" : "ı", "j" : "ſ", "k" : "ʞ", "l" : "ȷ", 
	    "m" : "ɯ", "n" : "u", "o" : "o", "p" : "d", 
	    "q" : "b", "r" : "ɹ", "s" : "s", "t" : "ʇ", 
	    "u" : "n", "v" : "ʌ", "w" : "ʍ", "x" : "x", 
	    "y" : "ʎ", "z" : "z", " " : " "}


# Start of program
#in_file_name = raw_input("Input file name : ")
in_file = open("input")
#out_file_name = raw_input("Output file name : ")
out_file = open("output", "w")

data = in_file.readlines()
for i in data:
	i=i.strip()  
	temp_str = ""
	i=i.lower()
	for j in range(0, len(i)):
		if i[j].isalpha():
			temp_str = char_dict[i[j]] + temp_str
		else:
			temp_str = i[j] + temp_str
	print (temp_str)
	temp_str=temp_str+'\n'
	out_file.write(temp_str)
in_file.close()
out_file.close()

