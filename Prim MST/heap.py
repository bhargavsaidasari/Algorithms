def swap(array,index_1,index_2):
    array[index_1],array[index_2] = array[index_2],array[index_1]

class Heap:

    def __init__(self,array,indices):
        self.array = array
        #Indices to keeptrack of the original location of each element in the heap
        self.indices = indices
        self.__heapify()
    
    def __str__(self):
        return

    def __repr__(self):
        return
    
    def __heapify(self):

        for i in range(len(self.array)-1,-1,-1):
            self.__bubbleDown(i)
        return

    def __bubbleDown(self,index):

        leftChild = 2*index+1
        rightChild = 2*index+2
        
        if(leftChild > len(self.array)-1):
            return

        elif(leftChild == len(self.array)-1):
            if(self.array[leftChild]<self.array[index]):
                swap(self.array,index,leftChild)
                swap(self.indices,index,leftChild)
            return

        else:
            if(self.array[leftChild]<self.array[index] and \
                self.array[leftChild]<=self.array[rightChild]):

                swap(self.array,index,leftChild)
                swap(self.indices,index,leftChild)

                self.__bubbleDown(leftChild)

            elif(self.array[rightChild]<self.array[index] and \
                    self.array[rightChild]<self.array[leftChild]):
                swap(self.array,index,rightChild)
                swap(self.indices,index,rightChild)
                self.__bubbleDown(rightChild)
        
        return

    def __bubbleUp(self,index):
        parent = int((index-1)/2)
        if(parent < 0 or index>=len(self.array)):
            return
        elif(self.array[index]<self.array[parent]):
            swap(self.array,index,parent)
            swap(self.indices,index,parent)
            self.__bubbleUp(parent)

        return

    def extractMin(self):
        swap(self.array,0,len(self.array)-1)
        swap(self.indices,0,len(self.indices)-1)
        shortestPath = self.array.pop()
        shortestNode = self.indices.pop()
        self.__bubbleDown(0)
        return(shortestPath,shortestNode)

    def insertElement(self,value,index):
        self.array.append(value)
        self.indices.append(index)
        self.__bubbleUp(len(self.array)-1)

    def deleteElement(self,loc):
        swap(self.array,loc,len(self.array)-1)
        swap(self.indices,loc,len(self.indices)-1)
        self.array.pop()
        self.indices.pop()
        self.__bubbleDown(loc)
        self.__bubbleUp(loc)

    def lookupNode(self,Node):
        for nodeIndex in range(len(self.indices)):
            if Node == self.indices[nodeIndex]:
                return(nodeIndex)
        return(False) 