#function definitions
def generateSortFactors(noOfMappers):
	ret = []
	for m in noOfMappers:
		for i in range(1, m+1):
			if ret.count(i)==0:
				ret.append(i)
		
	return ret

def getOutputCombinations(osortmb, omaxMappers, osortfactor, omaxReducers, ospillPercent, ojavaOpts):
	ret = []
	for a in osortmb:
		for b in omaxMappers:
			for c in osortfactor:
				for d in omaxReducers:
					for e in ospillPercent:
						for f in ojavaOpts:
							ret.append([a, b, c, d, e, f])
	return ret


def getFinalCombinations(inputCombinations, outputCombinations):
	ret = []
	for a in inputCombinations:
		for b in outputCombinations:
			ret.append(a+b)
	return ret
	
def getInputCombinations(idataSize, inumberNodes, inumberReplicas, inumberOfCores):
	ret = []
	for a in idataSize:
			for b in inumberNodes:
				for c in inumberReplicas:
					for d in inumberOfCores:
						if d >= c:
							ret.append([a, b, c, d])
	return ret
#Inputs

idataSize = [1, 2, 5, 10, 20, 40, 80, 160] #in MBs
inumberNodes = [4, 10]
inumberReplicas = [2, 6]
inumberOfCores = [4]


#Outputs
osortmb = [100, 150, 200, 250]
omaxMappers = [inumberOfCores[0] - 1]
osortfactor = generateSortFactors(omaxMappers)
omaxReducers = omaxMappers
ospillPercent = [60, 100] #changed!
ojavaOpts = [256 / (omaxMappers[0] + 1)]

outputCombinations = getOutputCombinations(osortmb, omaxMappers, osortfactor, omaxReducers, ospillPercent, ojavaOpts)
inputCombinations = getInputCombinations(idataSize, inumberNodes, inumberReplicas, inumberOfCores)
finalCombinations = getFinalCombinations(inputCombinations, outputCombinations)


'''
	Indices of various parameters in "finalCombinations" are follows!
		
		#input Parameters
		0 - idataSize
		1 - inumberNodes
		2 - inumberReplicas
		3 - inumberOfCores
		
		#output Parameters:
		4 - osortmb
		5 - omaxMappers
		6 - osortfactor
		7 - omaxReducers
		8 - ospillPercent
		9 - ojavaOpts
		
'''
print inputCombinations
print len(inputCombinations), len(outputCombinations), len(finalCombinations)
