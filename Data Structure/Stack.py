class Pile :
    def __init__(self) :
        self.tab = []
        self.top = -1

    def add(self,e) :
        self.top += 1
        self.tab += [e]

    def pop(self) : 
        self.top -= 1
        self.tab.pop()

    def isemprty(self) :
        return self.top == -1

    def summit(self) :
        return self.tab[self.top]

    def print(self) :
        for i in range (self.top,-1,-1):
            print(self.tab[i])
    
