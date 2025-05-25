class Node:
    def __init__(self,value,next_node):
        self.value = value
        self.next_node: Node | None = next_node

class Head:
    def __init__(self):
        self.head: Node | None = None

    def add(self,value):
        if self.head == None:
            self.head = Node(value,None)
            return
        root = self.head
        while root.next_node:
            root = root.next_node
        root.next_node = Node(value,None)
        return

    def find(self,value):
        if self.head:
            node: Node = self.head
            while node.next_node:
                if node.value == value:
                    print(value,"found")
                    return
                node = node.next_node
        print(value,"not found")
        return

    def print_list(self):
        node = self.head
        while node:
            print(node.value, end="->")
            node = node.next_node
        print(None)
        return

    def remove(self,value):
        pass
            
        




linked_list = Head()
linked_list.add(5)
linked_list.add(42)
linked_list.add(5421)
linked_list.add(124)
linked_list.add(5422)
linked_list.add(8903)
linked_list.add(2333)
linked_list.add(9)


linked_list.find(14)


linked_list.print_list()
