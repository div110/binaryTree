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
            #print("iterace pro", value)
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

    def remove(self, root, value_to_delete):



        #deleting right  
        if root.rightchild and root.rightchild.value == value_to_delete:
            if root.rightchild.leftchild == None and root.rightchild.rightchild == None:
                root.rightchild = None
                return
            elif root.rightchild.leftchild == None and root.rightchild.rightchild:
                root.rightchild = root.rightchild.rightchild
                return
            elif root.rightchild.rightchild == None and root.rightchild.leftchild:
                root.rightchild = root.rightchild.leftchild
                return
            elif root.rightchild.leftchild and root.rightchild.leftchild:
                node = root.rightchild.rightchild
                while node.leftchild:
                    node = node.leftchild
                value = node.value
                self.remove(strom.root,value)
                root.rightchild.value = value
                return


        #deleting left 
        elif root.leftchild and root.leftchild.value == value_to_delete:

            if root.leftchild.leftchild == None and root.leftchild.rightchild == None:
                root.leftchild = None
                return

            elif root.leftchild.rightchild == None and root.leftchild.leftchild:
                root.leftchild = root.leftchild.leftchild
                return

            elif root.leftchild.leftchild == None and root.leftchild.rightchild:
                root.leftchild = root.leftchild.rightchild
                return

            elif root.leftchild.leftchild and root.leftchild.rightchild:
                node = root.leftchild.rightchild
                while node.leftchild:
                    node = node.leftchild
                value = node.value
                self.remove(strom.root,value)
                root.leftchild.value = value
                return



        if value_to_delete < root.value:
            self.remove(root.leftchild, value_to_delete)
        elif value_to_delete > root.value:
            self.remove(root.rightchild, value_to_delete)



class Node:
    def __init__(self,value, leftchild, rightchild):
        self.value = value
        self.leftchild: Node | None = leftchild
        self.rightchild: Node | None = rightchild

strom = Tree()
#print(strom.root)

strom.add(100)
strom.add(1000)
strom.add(500)
strom.add(1500)

strom.remove(strom.root, 1000)


strom.find(500)
strom.find(1000)
strom.find(1500)
