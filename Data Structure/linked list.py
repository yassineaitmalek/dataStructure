class Node :
    def __init__(self,e=None) :
        self.element = e
        self.next = None
        self.prev = None



class Linked_list_doubely :
    def __init__(self) :
        self.head = None
       

    def addend(self,e):
        node = Node(e)
        if self.head == None  :
            self.head =  node
        else :
            node.next = None
            cur = self.head
            while cur.next :
                cur = cur.next
            node.prev = cur
            cur.next = node

    def addfirst(self,e):
        if self.head is None:
            node = Node(e)
            self.head = node
        else:
            node = Node(e)
            self.head.prev = node
            node.next = self.head
            self.head = node

    def len(self) :
        if self.head == None :
            return 0
        else :
            i = 0
            cur = self.head
            while cur :
                i+=1
                cur = cur.next
            
            return i
    def access(self,index):
        if self.head == None or index > self.len() :
            
            return False
        else : 
            i = 0
            cur = self.head
            while i <= index:
                if i == index :
                    return cur.element
                cur = cur.next
                i += 1
            
                 

    def search(self,e):
        cur = self.head
        while cur :
            if cur.element == e :

                return True
            cur = cur.next

        return False

    def remove(self,place):
        if self.head == None or place > self.len() :
            print("Error")
            return False
        if place == 0 :
            deleted = self.head.element
            self.head = self.head.next
            print("Succes deleted is ",deleted)

            return True
        else :
            index = 0 
            cur = self.head
            while index <= place :
                cur.prev = cur
                cur = cur.next
                index += 1
                if index == place :
                    deleted = cur.element
                    cur.prev.next = cur.next
                    print("Succes deleted is ",deleted)
                    break
            return True



    def print(self):
        cur = self.head
        while cur  :
            print(cur.element)
            cur = cur.next

