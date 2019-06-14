#!/usr/bin/env python3

import random
#class spin:
#	 def __init__(self, rzeczywista, urojona):

def DeltaE(spin, J, K, Hmi):
	nawias = 0.
	for i in spin:
			nawias += i
	nawias *=J
	nawias += Hmi
	return -2.*K*nawias

def Try(table, J, x, y, Hmi, kT, L):
	
	# periodyczne warunki brzegowe
	xu = x + 1
	yu = y + 1
	xd = x - 1
	yd = y - 1
	
	if xd == -1 :
		xd = L-1
	if xu == L :
		xu = 0  
	
	if yd == -1 :
		yd = L-1
	if yu == L :
		yu = 0  

	otoczenie = [ table[xu][y] , table[xd][y], table[x][yu], table[x][yd] ]	

	DE = DeltaE( otoczenie, J, table[x][y], Hmi )
	
	if DE < 0 :
		return True 	
	else :
		e = 2.71
		R = random.random()
		E = e**(-DE / kT)
		if R < E :
			return True
		else :
			return False

def Change( i ): 
	if i == -1:
		return 1
	elif i == 1:
		return -1
	else:
		return 0
def Play():
	L = 32
	#siec = [[ 1 for i in range(L) ] for i in range(L)]
	#print (siec)
	T = 300
	k = 1.38*(10**(-23))
	mi = 1./2
	J =  -1e-21
	H = 0
	N = L*L
	with open('input') as plik:
		siec = [list(map(int, wiersz.split('\t'))) for wiersz in plik]
	plik.close()
	#plik = open('input')
	#try:
	#	siec = plik.read()
	#finally:
	#	plik.close()
	M = 10000
	
	#print (siec)
	# sekwencyjnie
	for m in range(0, M):
		for i in range(0,L):
			for j in range(0,L):
				if Try(siec, J, i, j, H*mi, k*T, L) :
					siec[i][j] = Change( siec[i][j] )
	
	#print (siec)
	
	outfile =  open('output', 'w');
	for i in range(0,L):
		line = ''
		for j in range(0,L):
			line += str(siec[i][j]) + '\t'
		line +=  '\n'
		outfile.write(line)
	
	outfile.close()
	return 0
