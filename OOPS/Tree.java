import javax.xml.transform.SourceLocator;

public class Tree {
    public static void main(String args[])
    {
        int nodes[] = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        // BinaryTree tree = new BinaryTree();
        Node root = BinaryTree.buildTree(nodes);
        System.out.println(root.data);
        BinaryTree.preOrder(root);
        System.out.println();
        BinaryTree.inOrder(root);
        System.out.println();
        BinaryTree.postOrder(root);
    }
    
}

class Node {
    int data;
    Node left;
    Node right;
     
    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    static int idx = -1;
    public static Node buildTree(int nodes[])
    {
        idx++;
        if(nodes[idx]==-1)
        {
            return null;
        }

        Node newNode = new Node(nodes[idx]);
        newNode.left = buildTree(nodes);
        newNode.right = buildTree(nodes);
        
        return newNode;

    }

    public static void preOrder(Node root)
    {
        if(root==null)
        {
            return;
        }
        System.out.print(root.data+" ");
        preOrder(root.left);
        preOrder(root.right);
        return;
    }

    
    public static void inOrder(Node root)
    {
        if(root==null)
        {
            return;
        }
        preOrder(root.left);
        System.out.print(root.data+" ");
        preOrder(root.right);
        return;
    }

    
    public static void postOrder(Node root)
    {
        if(root==null)
        {
            return;
        }
        preOrder(root.left);
        preOrder(root.right);
        System.out.print(root.data+" ");
        return;
    }

}