import re
from heap import *


adjacencyMatrix = [[1000000 for x in range(200)] for y in range(200)]

with open('hw2.txt','r') as f:
    for currentLine in f.readlines():
        nodes = re.split('\t|\n',currentLine)
        nodes = list(filter(None,nodes))
        parentNode = int(nodes[0])-1
        #print(nodes)
        for i in range(1,len(nodes)):
            childNode = int(nodes[i].split(',')[0])-1
            adjacencyMatrix[parentNode][childNode] = int(nodes[i].split(',')[1])

adjacencyMatrix2 = adjacencyMatrix.copy()

def updateDistances(djikstraHeap,newTraversed,pathValue):
    for i in range(len(djikstraHeap.indices)):
        currentNode = djikstraHeap.indices[i]
        ##check if the recently popped node has a connection to the current
        if(adjacencyMatrix[newTraversed][currentNode] == 1e6):
            continue
        else:
            currentDist = adjacencyMatrix[newTraversed][currentNode]
            if(djikstraHeap.array[i] > pathValue+currentDist):
                djikstraHeap.deleteElement(i)
                djikstraHeap.insertElement(currentDist+pathValue,currentNode)

length = len(adjacencyMatrix[0][:])
traversedNodes = [0]
djikstraPaths = [0 for x in range(length)]
djikstraHeap = Heap(adjacencyMatrix[0][:],list(range(length)))#200 is the number of nodes 

while(len(traversedNodes)!=length+1):
    shortestPath,shortestNode = djikstraHeap.extractMin()
    #check if the node already had one shortest path output
    djikstraPaths[shortestNode] = shortestPath
    traversedNodes.append(shortestNode)
    
    for i in traversedNodes:
        adjacencyMatrix[shortestNode][i] = 1e6
    updateDistances(djikstraHeap,shortestNode,shortestPath)

print(djikstraPaths)

