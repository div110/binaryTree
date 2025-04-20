class Tree:
    def __init__(self):
        self.root = None

    def add(self,value):
        node = Node(value,None,None)
        root = self.root
        #print(self.root)
        if root == None:
            
            self.root = node 
            return
        while True:
            print("iterace pro", value)
            if value == root.value:
                return
            elif value < root.value:
                if root.leftchild == None:
                    root.leftchild = node
                    return
                else:
                    root = root.leftchild
            elif value > root.value:
                if root.rightchild == None:
                    root.rightchild = node
                    return
                else:
                    root = root.rightchild


    def find(self,value):
        root = self.root
        if root == None:
            print("tree is empty")
            return

        while True:
            if value == root.value:
                print(value, "found")
                return
            elif value < root.value:
                if root.leftchild == None:
                    print(value, "not found")
                    return
                else:
                    root = root.leftchild
            elif value > root.value:
                if root.rightchild == None:
                    print(value, "not found")
                    return
                else:
                    root = root.rightchild


class Node:
    def __init__(self,value, leftchild, rightchild):
        self.value = value
        self.leftchild = leftchild
        self.rightchild = rightchild

strom = Tree()
print(strom.root)
strom.add(1)
strom.add(2)
strom.add(3)
strom.add(4)
strom.add(5)
strom.add(6)
strom.add(7)

strom.find(3)

