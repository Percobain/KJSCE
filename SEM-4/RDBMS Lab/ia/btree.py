# btree.py
class BTreeNode:
    def __init__(self, t, leaf=True):
        self.t = t  # Minimum degree
        self.keys = []  # Keys
        self.children = []  # Child pointers
        self.leaf = leaf  # Is leaf or not
        
    def __str__(self):
        if self.leaf:
            return str(self.keys)
        return f"{self.keys} -> {[str(child) for child in self.children]}"

class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t, True)
        self.t = t
        
    def search(self, k, x=None):
        if x is None:
            x = self.root
        i = 0
        while i < len(x.keys) and k > x.keys[i]:
            i += 1
        if i < len(x.keys) and k == x.keys[i]:
            return (x, i)
        if x.leaf:
            return None
        return self.search(k, x.children[i])
    
    def insert(self, k):
        root = self.root
        if len(root.keys) == (2 * self.t) - 1:
            temp = BTreeNode(self.t, False)
            self.root = temp
            temp.children.insert(0, root)
            self._split_child(temp, 0)
            self._insert_non_full(temp, k)
        else:
            self._insert_non_full(root, k)
    
    def _split_child(self, x, i):
        t = self.t
        y = x.children[i]
        z = BTreeNode(t, y.leaf)
        
        x.keys.insert(i, y.keys[t-1])
        
        z.keys = y.keys[t:(2*t-1)]
        y.keys = y.keys[0:(t-1)]
        
        if not y.leaf:
            z.children = y.children[t:(2*t)]
            y.children = y.children[0:t]
        
        x.children.insert(i+1, z)
    
    def _insert_non_full(self, x, k):
        i = len(x.keys) - 1
        if x.leaf:
            while i >= 0 and k < x.keys[i]:
                i -= 1
            x.keys.insert(i + 1, k)
        else:
            while i >= 0 and k < x.keys[i]:
                i -= 1
            i += 1
            if len(x.children[i].keys) == (2 * self.t) - 1:
                self._split_child(x, i)
                if k > x.keys[i]:
                    i += 1
            self._insert_non_full(x.children[i], k)