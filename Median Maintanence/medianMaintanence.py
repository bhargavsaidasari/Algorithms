from heap import *

minimumHeap = Heap([])
maximumHeap = Heap([])
medianList = []

def median(minimumHeap,maximumHeap):
    if(minimumHeap.getLength()==maximumHeap.getLength()):
        return(-maximumHeap.getMin())
    elif(minimumHeap.getLength()>maximumHeap.getLength()):
        return(minimumHeap.getMin())
    else:
        return(-maximumHeap.getMin())

with open('hw6.txt','r') as f :
    #read the first integer into maximum heap 
    maximumHeap.insertElement(-int(f.readline()))
    for currentline in f.readlines():
        currentInteger = int(currentline)
        #update median
        medianList.append(median(minimumHeap,maximumHeap))
        #balancing act between maximum and minimum heaps
        # Eg: 1,2,3,4,5
        #maximum heap -2 -1 minim heap : 3,4,5

        if(maximumHeap.getLength()>minimumHeap.getLength()):
            if(currentInteger < -maximumHeap.getMin()):
                minimumHeap.insertElement(-maximumHeap.extractMin())
                maximumHeap.insertElement(-currentInteger)
            else:
                minimumHeap.insertElement(currentInteger)
        
        elif(maximumHeap.getLength() < minimumHeap.getLength()):
            if(currentInteger > minimumHeap.getMin()):
                maximumHeap.insertElement(-minimumHeap.extractMin())
                minimumHeap.insertElement(currentInteger)
            else:
                maximumHeap.insertElement(-currentInteger)
        
        else:
            if(currentInteger > minimumHeap.getMin()):
                minimumHeap.insertElement(currentInteger)
            else:
                maximumHeap.insertElement(-currentInteger)

#update the final median
medianList.append(median(minimumHeap,maximumHeap))
print(sum(medianList))