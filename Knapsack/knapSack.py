import re


def updateCache(cache,itemSize,itemValue):

    cache[1][0:itemSize] = cache[0][0:itemSize]

    for weight in range(len(cache[0][itemSize:])):
        cache[1][weight+itemSize] = max(cache[0][weight] + itemValue , \
            cache[0][weight+itemSize])

    cache[0] = cache[1]
    cache[1] = [0]*len(cache[0])


    #load the file

with open('knapSack.txt','r') as valuesFile:
    problemInfo = re.split(r'\s|\n|\t',valuesFile.readline())
    knapsackSize = int(problemInfo[0]) + 1
    numItems = int(problemInfo[1])
    cacheOptimal = [[0 for x in range(knapsackSize)] for y in range(2)]
    currentItemIndex = 0

    for item in valuesFile.readlines():
        
        print(currentItemIndex)
        currentItemInfo = re.split(r'\s|\t|\n',item)
        currentItemInfo = list(filter(None,currentItemInfo))
        currentItemInfo = [int(x) for x in currentItemInfo]
        currentItemSize = currentItemInfo[1]
        currentItemValue = currentItemInfo[0]
        if(currentItemIndex == 0):
            if(currentItemSize <= knapsackSize) :
                cacheOptimal[currentItemIndex][currentItemSize:] = [currentItemValue] * (knapsackSize - currentItemSize)     
        else:
            updateCache(cacheOptimal,currentItemSize,currentItemValue)
        currentItemIndex = currentItemIndex + 1    
        continue

    print('Done')
    print(max(cacheOptimal[0]))