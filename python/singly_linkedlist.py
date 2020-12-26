class LinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
    
    def get_head(self):
        return self.__head
    
    def get_tail(self):
        return self.__tail
    
    def add(self,data):
        if self.__head:
            temp = self.__head
            while temp.get_next():
                temp = temp.get_next()
            temp.set_next(Node(data))
            self.__tail = temp.get_next()
        else:
            new_node = Node(data)
            self.__head = new_node
            self.__tail = self.__head
    
    def isempty(self):
        if self.__head == None:
            return True
        return False
    
    def get_size(self):
        if self.__head:
            count = 1
            temp = self.__head
            while temp:
                temp = temp.get_next()
                if temp:
                    count+=1
            return count
        else:
            return 0
    
    def findNode(self,data):
        temp = self.__head
        while temp:
            if temp.get_data() == data:
                print('node found')
                return temp
            temp = temp.get_next()
        else:
            return None
    
    def insert(self,data,prev_data):
        node = self.findNode(prev_data)
        new_node = Node(data)
        if node:
            if node == self.__head.get_data():
                if self.__head == self.__tail:
                    self.__head.set_next(node)
                    self.__tail = node
                else:
                    node.set_next(self.__head.get_next())
                    self.set_next(node)
            else:
                temp = self.__head
                while temp:
                    if temp == node:
                        new_node.set_next(temp.get_next())
                        temp.set_next(new_node)
                        if self.__tail == temp:
                            self.__tail = temp.get_next()
                        break
                    temp = temp.get_next()
                        
        else:
            print('data not found')
    
    def delete(self,data):
        node = self.findNode(data)
        if node:
            if node == self.__head.get_data():
                if self.__head == self.__tail:
                    self.__head,self.__tail=None,None
                else:
                    self.__head = node.get_next()
            else:
                temp = self.__head
                while temp:
                    if temp.get_next() == node:
                        temp.set_next(node.get_next())
                        if node == self.__tail:
                            self.__tail = temp
                        break
                    temp = temp.get_next()
        else:
            print('data is not found')
        
    
    def display(self):
        temp = self.__head
        while temp:
            print(temp.get_data(),end=' ')
            temp = temp.get_next()
    
    def reverse(self):
        current = self.__head
        self.__head = self.__tail
        self.__tail = current
        prev = None
        while current:
            next = current.get_next()
            if current:
                current.set_next(prev)
                prev = current
                current = next            
