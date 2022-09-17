import javax.management.ObjectName;
import javax.rmi.ssl.SslRMIClientSocketFactory;

public class ThreadDemo {
    public static void main(String args[]) {
        PrintNumber obj = new PrintNumber();
        // new Odd(obj);
        // new Even(obj);


        Odd obj1 = new Odd(obj);
        Even obj2 = new Even(obj);


        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        
        t1.start();
        try{
            Thread.sleep(50);
        }
        catch (Exception e) {}
        t2.start();

        
        // Thread t1 = new Thread(
        //     () -> 
        //     {
        //         for(int i=1;i<=10;i=i+2)
        //         {
        //             System.out.print(i+" ");
        //             try{
        //                 Thread.sleep(500);
        //             }
        //             catch (Exception e) {}
        //         }
        //     }
        // );
        // Thread t2 = new Thread(
        //     () -> 
        //     {
        //         for(int i=2;i<=10;i=i+2)
        //         {
        //             System.out.print(i+" ");
        //             try{
        //                 Thread.sleep(500);
        //             }
        //             catch (Exception e) {}
        //         }
        //     }
        // );
        
        // t1.start();
        // try{
        //     Thread.sleep(50);
        // }
        // catch (Exception e) {}
        // t2.start();
    }

}



// class Odd extends Thread {
//     public void run()
//     {
//         for(int i=1;i<=10;i=i+2)
//         {
//             System.out.print(i+" ");
//             try{
//                 Thread.sleep(500);
//             }
//             catch (Exception e) {}
//         }
//     }
// }

// class Even extends Thread {
//     public  void run()
//     {
//         for(int i=2;i<=10;i=i+2)
//         {
//             System.out.print(i+" ");
//             try{
//                 Thread.sleep(500);
//             }
//             catch (Exception e) {}
//         }
//     }
// }


class PrintNumber {
    boolean oddTern = true;

    public synchronized void printOdd()
    {
        for(int i=1;i<=10;i=i+2)
        {
            while(!oddTern)
            {
                try{ wait();} catch(Exception e) {}
            }
            System.out.println(i+" ");
            oddTern=false;
            try { Thread.sleep(500);} catch(Exception e) {}
            notify();
        }
    }

    public synchronized void printEven()
    {
        for(int i=2;i<=10;i=i+2)
        {
            while(oddTern)
            {
                try { wait();} catch (Exception e){}
            }
            System.out.println(i+" ");
            oddTern=true;
            
            try { Thread.sleep(500);} catch(Exception e) {}
            notify();
        }
    }
}

class Odd implements Runnable{
    PrintNumber obj ;
    Odd(PrintNumber obj)
    {
        this.obj = obj;
        // Thread t = new Thread(this,"odd");
        // t.start();
    }
    public void run()
    {
        obj.printOdd();
    }



    // public synchronized void run()
    // {
    //     for(int i=1;i<=10;i=i+2)
    //     {
    //         try{
    //             wait();
    //             // Thread.sleep(500);
    //         }
    //         catch (Exception e) {}
    //         System.out.print(i+" ");
    //         notify();
            
    //     }
    // }
}

class Even implements Runnable {
    PrintNumber obj;
    Even(PrintNumber obj)
    {
        this.obj = obj;
        // Thread t =  new Thread(this,"Even");
        // t.start();
    }

    public void run()
    {
        obj.printEven();
    }

    
    
    
    // public synchronized  void run()
    // {
    //     for(int i=2;i<=10;i=i+2)
    //     {
    //         try{
    //             wait();
    //             // Thread.sleep(500);
    //         }
    //         catch (Exception e) {}
            
    //         System.out.print(i+" ");
            
    //         notify();
    //     }
    // }
}