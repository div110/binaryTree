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

    def remove(self, value_to_delete):
    
        root = self.root
        if root == None:
            print("tree is empty")
            return
        while True:
            if value_to_delete < root.value and root.leftchild != None:
                temp = node
                root = temp
                node = root.leftchild
                print("went left")
            elif value_to_delete > root.value and root.rightchild != None:
                temp = node
                root = temp
                node = root.rightchild
                print("went right")
            
            if node.value == value_to_delete:
                if node.leftchild == None and node.rightchild == None:
                    if node == root.leftchild:
                        root.leftchild = None
                    elif node == root.rightchild:
                        root.rightchild = None
                    print(value_to_delete,"deleted")
                    return





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

strom.find(1)
strom.find(2)
strom.find(3)

strom.remove(3)
strom.find(3)
