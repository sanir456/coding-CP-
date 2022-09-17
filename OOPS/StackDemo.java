
public class StackDemo {
    public static void main(String args[])
    {
        Stack s = new Stack(3);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        System.out.println(s.peek());
        s.pop();
        System.out.println(s.peek());
        s.pop();
        s.pop();
        s.pop();
        System.out.println(s.peek());
    }   
}

class Stack {
    int arr[];
    int top;
    Stack(int n)
    {
        arr = new int[n];
        top=0;
    }

    public boolean isEmpty()
    {
        if(this.top==0)
        {
            return true;
        }
        return false;
    }

    public boolean isFull()
    {
        if(this.top==arr.length)
        {
            return true;
        }
        return false;
    }

    public void pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty");
            return;
        }
        this.top--;
    }
    public void push(int val)
    {
        if(isFull())
        {
            System.out.println("Stack is full");
            return;
        }
        this.arr[this.top]=val;
        this.top++;
    }

    public int peek()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty");
            return -1;
        }
        return this.arr[top-1];
    }

    
}
