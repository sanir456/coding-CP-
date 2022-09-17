import java.util.ArrayList;
import java.util.Collections;
public class ArrayListHelp {
    public static void main(String args[])
    {
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(0);
        list.add(2);
        System.out.println(list);
        System.out.println(list.get(0));
        list.add(1,1);
        System.out.println(list);
        list.remove(2);

        System.out.println(list);
        System.out.println(list.size());

        for(Integer i : list)
        {
            System.out.println(i);
        }
        Collections.sort(list);
        System.out.println(list);
    }
}
