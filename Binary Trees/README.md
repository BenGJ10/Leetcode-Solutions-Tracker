# Binary Trees – Complete Patterns

Binary Trees are hierarchical data structures with **nodes** containing data and pointers to **left** and **right** children. Each node has at most two children, forming a tree structure. Binary trees are fundamental for representing hierarchical relationships and are crucial for understanding more complex structures like BSTs, heaps, and tries.

The key ideas:  
- **Root**: Topmost node with no parent.  
- **Left/Right children**: Subtrees rooted at each child.  
- **Height/Depth**: Distance from root to deepest/shallowest leaf.  
- **Traversal**: Visit nodes in specific orders (Pre/In/Post-order, Level-order).  
- **Recursion**: Most tree problems use recursive divide-and-conquer approach.  

---

## Patterns in Binary Trees

### 1. Tree Traversals (Pre/In/Post-order, Level-order)

Visit all nodes in specific orders for processing or building.

#### Idea and Approach
- **Pre-order**: Root → Left → Right (DFS, pre-visit)  
- **In-order**: Left → Root → Right (DFS, BST sorted order)  
- **Post-order**: Left → Right → Root (DFS, post-visit)  
- **Level-order**: BFS, process level by level using queue  

#### Algorithm (Recursive In-order)
1. If `root == nullptr`, return.  
2. Recurse on left subtree.  
3. Process `root->val`.  
4. Recurse on right subtree.  

#### C++ Example
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive traversals
void preorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

void postorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

// Iterative level-order
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

#### Important Problems

- [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
- [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

---

### 2. Tree Properties (Height, Depth, Size, Balance)

Calculate structural properties of the tree.

#### Idea and Approach

- **Height**: Max depth of any node from root (0 for leaf).  
- **Depth**: Distance from root to current node.  
- **Size**: Total number of nodes.  
- **Balance**: Height difference between left/right ≤ 1.  

#### Algorithm (Height Calculation)
1. If `root == nullptr`, return 0.  
2. Recursively compute `leftHeight = height(root->left)`.  
3. Recursively compute `rightHeight = height(root->right)`.  
4. Return `1 + max(leftHeight, rightHeight)`.  

#### C++ Example
```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int size(TreeNode* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

bool isBalanced(TreeNode* root) {
    int balance = 0;
    return isBalancedHelper(root, balance) != -1;
}

int isBalancedHelper(TreeNode* root, int& balance) {
    if (!root) return 0;
    
    int leftHeight = isBalancedHelper(root->left, balance);
    if (leftHeight == -1) return -1;
    
    int rightHeight = isBalancedHelper(root->right, balance);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1) return balance = -1;
    
    return 1 + max(leftHeight, rightHeight);
}
```

#### Important Problems

- [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
- [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
- [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

---

### 3. Path Problems (Root-to-Leaf, Node-to-Node)

Find paths satisfying specific conditions from root to leaves or between nodes.

#### Idea and Approach

- **Root-to-Leaf**: Backtracking with path accumulation.  
- **Node-to-Node**: Find paths to LCA, then combine.  
- **Sum/Path constraints**: Check condition at each step.  

#### C++ Example
```cpp
// Path Sum II - All paths from root to leaf summing to target
void pathSum(TreeNode* root, int target, vector<vector<int>>& result, 
             vector<int>& path, int currSum) {
    if (!root) return;
    
    path.push_back(root->val);
    currSum += root->val;
    
    if (!root->left && !root->right && currSum == target) {
        result.push_back(path);
    } else {
        pathSum(root->left, target, result, path, currSum);
        pathSum(root->right, target, result, path, currSum);
    }
    
    path.pop_back(); // Backtrack
}

// Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}
```

#### Important Problems

- [112. Path Sum](https://leetcode.com/problems/path-sum/)
- [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)
- [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

---

### 4. Level Order Variations (Zigzag, Right View, Vertical)

Process nodes level by level with specific ordering or filtering.

#### Idea and Approach

- **Zigzag**: Alternate direction per level using deque or reverse.  
- **Right View**: Track rightmost node per level.  
- **Vertical**: Group nodes by horizontal distance from root.  

#### C++ Example
```cpp
// Zigzag Level Order
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            int idx = leftToRight ? i : size - 1 - i;
            level[idx] = node->val;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        result.push_back(level);
    }
    return result;
}

// Right Side View
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (i == size - 1) result.push_back(node->val); // Rightmost
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}
```

#### Important Problems

- [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
- [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
- [662. Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

---

### 5. Tree Modification (Flatten, Serialize, Construct)

Transform tree structure or convert between representations.

#### Idea and Approach

- **Flatten**: Convert to right-skewed linked list (pre-order traversal).  
- **Serialize**: Encode tree to string (pre/in-order + markers).  
- **Construct**: Build tree from traversals or encoded string.  

#### C++ Example
```cpp
// Flatten Binary Tree to Linked List
void flatten(TreeNode* root) {
    if (!root) return;
    
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pred = curr->left;
            while (pred->right) pred = pred->right;
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

// Serialize and Deserialize
string serialize(TreeNode* root) {
    if (!root) return "N,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode* deserialize(string& data, int& pos) {
    if (data[pos] == 'N') {
        pos += 2; // Skip "N,"
        return nullptr;
    }
    
    int val = 0;
    while (data[pos] != ',') {
        val = val * 10 + (data[pos] - '0');
        pos++;
    }
    pos++; // Skip ','
    
    TreeNode* node = new TreeNode(val);
    node->left = deserialize(data, pos);
    node->right = deserialize(data, pos);
    return node;
}
```

#### Important Problems

- [114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
- [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
- [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)


---

### More Important Binary Tree Problems

Here's a list of additional must-practice problems:

- [100. Same Tree](https://leetcode.com/problems/same-tree/)  
- [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)  
- [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)  
- [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)  
- [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)  
- [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)  
- [814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)  
- [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)  

---
