class data:
    def __init__(self,key,value):
        self.key = key
        self.value = value
        self.chain = -1
  
class Hashing:
    def __init__(self):
        self.M = int(input("Enter Size of Table = "))
        self._table = [data(-1,-1)]*(self.M)
        
    def display(self):
        print("INDEX\tKEY\tVALUE\tCHAIN")
        for i in range(self.M):
            print("%d\t %d\t %s\t %d"%(i,self._table[i].key,self._table[i].value,self._table[i].chain))
            
    def insertWO(self, key,val=0):
        self.index = (key)%(self.M) #Hash Function
        if(self._table[self.index].key == -1):
            self._table[self.index] = data(key,val)
            return
        
        else: #Collision Occured, using linear probing for resolving it
            for i in range(1,self.M):
                self.index = (key + i)%(self.M) #Linear Probing
                if(self._table[self.index].key == -1):
                    #For Chaining
                    j = 0 
                    while(j<self.M):
                        if((self._table[j].key)%self.M==key%self.M and self._table[j].chain==-1):
                            self._table[j].chain = self.index
                            break
                        j+=1
                        
                    self._table[self.index] = data(key,val)
                    print("%d inserted at index %d"%(key, self.index))
                    break
            else:
                print("Record Insertion Failed")
                
    def insertW(self,key,value):
        self.index = key%self.M
        if(self._table[self.index].key==-1):
            self._table[self.index] = data(key,value)
            return self.index
        
        elif((self._table[self.index].key)%self.M!=self.index):#If non deserving element occupied it
            p = self._table[self.index]
            self._table[self.index] = data(key,value)
            i = self.index+1
            while(i%self.M != self.index):
                if(self._table[i].key==-1):
                    self._table[i] = p
                    q = i
                    break
                i = (i+1)%self.M
            for j in range(self.M):
                if(self.index==self._table[j].chain):
                    print(self._table[j].chain)
                    self._table[j].chain = q
                    break
            return i
        
        else:
            for i in range(1,self.M):
                self.index = (key + i)%(self.M)
                if(self._table[self.index].key == -1):
                    j = key%self.M
                    while(j<self.M):
                        if((self._table[j].key)%self.M==key%self.M and self._table[j].chain==-1):
                            self._table[j].chain = self.index
                            break
                        j+=1
                    self._table[self.index] = data(key,value)
                    print("%d inserted at index %d"%(key, self.index))
                    break

    def search(self, key):
        self.count = 1
        for i in range(self.M):
            self.index = (key + i)%(self.M)
            if(self._table[self.index].key == key):
                print("\n%d found at index %d"%(key, self.index))
                print("Value stored at %d = %s"%(key,self._table[self.index].value))
                print("%d comparisons required"%(self.count))
                return self.index
            
            elif(self._table[self.index].chain!=-1):
                while(self._table[self.index].chain!=-1):
                    if(self._table[self._table[self.index].chain].key == key):
                        print("With the help of Chaining",self.index)
                        print("\n%d found at index %d"%(key, self.index))
                        print("Value stored at %d = %d"%(key,self._table[self.index].value))
                        print("%d comparisons required"%(self.count))
                        return self._table[self.index].chain
                    self.index = self._table[self.index].chain
            else:
                self.count += 1
        else:
            print("Sorry, Record not found")
            return -1
            
    def deleteKey(self,key):
        self.index = self.search(key)
        if(self.index!=-1):
            self._table[self.index].key = -1
            self._table[self.index].value = -1
            chainVal = self._table[self.index].chain
            self._table[self.index].chain = -1
            j = 0
            while(j<self.M):
                if(self._table[j].chain==self.index):
                    self._table[j].chain = chainVal
                    print("DELETED")
                    return
                j+=1
            
h = Hashing()
while(True):
    opt = int(input("\n_-_-_-_-_-_-_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_-_-_-_-_-_-_\n1)Insert a Data(With Replacement).\n2)Display Record.\n3)Search Record.\n4)EXIT.\n Enter Your Choice = "))
    if(opt==1):
        key = int(input("Enter Key = "))
        v = input("Enter Value for above key = ")
        h.insertW(key,v) 
    elif(opt==2):
        h.display()
    elif(opt==3):
        key = int(input("Enter Key = "))
        h.search(key)
    elif(opt==4):
        break
    else:
        print("Invalid Option")