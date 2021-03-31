class File :
    def __init__(self) :
        self.tab = []
        self.queue = -1

    def add(self,e) :
        self.queue += 1
        self.tab += [e]

    def pop(self) : 
        self.queue -= 1
        self.tab.pop(0)

    def isemprty(self) :
        return self.queue == -1

    def head(self) :
        return self.tab[0]

    def print(self) :
        for i in range (0,self.queue+1):
            print(self.tab[i])
