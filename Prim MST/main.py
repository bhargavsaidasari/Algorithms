import re
from heap import *

with open('edges.txt') as edges :
    graphInfo = [int(x) for x in re.split(r'\s|\t|\n',edges.readline())[:2]]
    adjacencyMatrix = [[1000000 for x in range(graphInfo[0])]for y in range(graphInfo[0])]
    for currentLine in edges.readlines():

        edgeInfo = [int(x) for x in re.split(r'\s|\t|\n',currentLine)[:3]]
        adjacencyMatrix[edgeInfo[0]-1][edgeInfo[1]-1] = edgeInfo[2]
        adjacencyMatrix[edgeInfo[1]-1][edgeInfo[0]-1] = edgeInfo[2]

def updateDistances(primHeap,newTraversed):
    listIndices = primHeap.indices.copy()
    for currentNode in listIndices:
        ##check if the recently popped node has a connection to the current
        if(adjacencyMatrix[newTraversed][currentNode] == 1e6):
            continue
        else:
            currentDist = adjacencyMatrix[newTraversed][currentNode]
            i = primHeap.lookupNode(currentNode)
            if(primHeap.array[i] > currentDist):
                primHeap.deleteElement(i)
                primHeap.insertElement(currentDist,currentNode)

length = len(adjacencyMatrix[0][:])
traversedNodes = [0]
MSTPaths = []

primHeap = Heap(adjacencyMatrix[0][:],list(range(length)))

while(len(traversedNodes)!=length):
    shortestPath,shortestNode = primHeap.extractMin()
    #check if the node already had one shortest path output
    MSTPaths.append(shortestPath)
    traversedNodes.append(shortestNode)
    
    for i in traversedNodes:
        adjacencyMatrix[shortestNode][i] = 1e6
        adjacencyMatrix[i][shortestNode] = 1e6
    updateDistances(primHeap,shortestNode)


print(sum(MSTPaths))




