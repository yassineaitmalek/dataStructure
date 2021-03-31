class Tree :
    def __init__(self,e=None):
        self.element = e
        self.rightchild = None
        self.leftchild = None

    def add(self,e):
        t = Tree(e)
        if self.element :
            if e < self.element :
                if self.leftchild is None :
                    self.leftchild = t
                else :
                    self.leftchild.add(e)
            
            else :
                if self.rightchild is None :
                    self.rightchild = t
                else :
                    self.rightchild.add(e)
        else :
            self.element = e
        return self

    def inorder(self):
        if self.leftchild:
            self.leftchild.inorder()
        print( self.element)
        if self.rightchild:
            self.rightchild.inorder()
    
    def isempty(self):
        return self.element == None

    def preorder(self) :
        print( self.element)
        if self.leftchild:
            self.leftchild.preorder()
        if self.rightchild:
            self.rightchild.preorder()
    def postorder(self) :
        if self.leftchild:
            self.leftchild.postorder()
        if self.rightchild:
            self.rightchild.postorder()
        print( self.element)
    
    def mintree(self):
        current = self  
        while(current.leftchild is not None): 
            current = current.leftchild 
    
        return current  
    
    def search(self, e):
        if self.element == e:
            return True

        if e < self.element:
            if self.leftchild:
                return self.leftchild.search(e)
            else:
                return False

        if e > self.element:
            if self.rightchild:
                return self.rightchild.search(e)
            else:
                return False

    
    def remove(self,e) :
        if self.isempty() :
            return None
        if e < self.element :
            self.leftchild = self.leftchild.remove(e)
        elif e > self.element :
            self.rightchild = self.rightchild.remove(e)
        else : 
            if self.leftchild is None:
                return self.rightchild
                         
            elif  self.rightchild is None:
                return self.leftchild
               
            
            t = self.rightchild.mintree()
            self.element = t.element
            self.rightchild = self.rightchild.remove(e)    
        return self
                
            




