class array:
    def __init__(self,max_size):
        self.__max_size = max_size
        self.__array = [None] * max_size
    
    def __str__(self):
        return str(self.__array)
    
    def get_size(self):
        return self.__max_size
    
    def is_full(self):
        if self.__array[-1] != None:
            return True
        return False
    
    def create_new_size_array(self,size,item=None):
        new_array = array(size)
        for i in range(size-1):
            new_array.__array[i] = self.__array[i]
        new_array.append(item)
        self.__array= new_array.__array
        self.__max_size = new_array.get_size()
        del(new_array)
        
    def append(self,item):
        if self.is_full():
            self.create_new_size_array(self.get_size() + 1, item)
        else:
            i=0
            while self.__array[i] != None:
                i+=1
            self.__array[i] = item 
        
    def insert(self,index,item):
        if self.__array[-1] == None:
            temp = self.__array
            self.create_new_size_array(self.get_size(),item)
            for i in range(index):
                self.__array[i] = temp[i]
            for i in range(index,self.get_size()):
                if temp[i]:
                    self.__array[i+1] = temp[i]
                else:
                    break
            self.__array[index] = item
        else:
            temp = self.__array
            self.create_new_size_array(self.get_size()+1,item)
            for i in range(index):
                self.__array[i] = temp[i]
            for i in range(index,self.get_size()-1):
                self.__array[i+1] = temp[i]
            self.__array[index] = item
    
    def delete(self,index):
        new_array = array(self.get_size())
        for i in range(index):
            new_array.__array[i] = self.__array[i]
        for i in range(index+1,self.get_size()):
            new_array.__array[i-1] = self.__array[i]
        self.__array = new_array.__array
