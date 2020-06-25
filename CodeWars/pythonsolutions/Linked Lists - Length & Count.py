#https://www.codewars.com/kata/55beec7dd347078289000021
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def length(node):
    count = 0
    if node == None:
        return count
    nt = node
    while nt != None:
        count+=1
        nt = nt.next
    return count

def count(node, data):
    count = 0
    if node == None:
        return count
    nt = node
    while nt != None:
        if nt.data == data:
            count+=1
        nt = nt.next
    return count