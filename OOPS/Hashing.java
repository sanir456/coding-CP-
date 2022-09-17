import java.util.*;

import javax.lang.model.util.ElementScanner6;
public class Hashing {
    public static void main(String args[])
    {
        HashSet<Integer> set = new HashSet<>();


        //insert
        set.add(1);
        set.add(2);
        set.add(3);
        set.add(1);

        if(set.contains(1))
        {
            System.out.println("set contains 1");
        }
        else
        {
            System.out.println("set not containes 1");
        }

        if(set.contains(4))
        {
            System.out.println("set contains 4");
        }
        else
        {
            System.out.println("set not containes 4");
        }

        Iterator it = set.iterator();
        while(it.hasNext())
        {
            System.out.println(it.next());
        }


        // HashMap<String, Integer> hm = new HashMap<>();
        
        //insert
        // hm.put("INDIA", 120);
        // hm.put("CHINA", 150);
        // hm.put("US", 30);
        // System.out.println(hm);
        // hm.put("CHINA", 180);
        // System.out.println(hm);

        //search
        // if(hm.containsKey("CHINA")){
        //     System.out.println("Present in map");
        // }
        // else {
        //     System.out.println("Not present in map");
        // }
        
        // if(hm.containsKey("INDONESIA")){
        //     System.out.println("Present in map");
        // }
        // else {
        //     System.out.println("Not present in map");
        // }

        // get
        // System.out.println( hm.get("CHINA"));
        // System.out.println( hm.get("INDONESIA"));
        

        //iteration
        // for(Map.Entry<String,Integer> e : hm.entrySet())
        // {
        //     System.out.println(e.getKey()+" "+e.getValue());
        // }

        //remove
        // hm.remove("CHINA");
        // System.out.println(hm);
        
    }
    
}
