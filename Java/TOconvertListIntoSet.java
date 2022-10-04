// ******************************Java Program to convert********************
//****************************** List to Set in Java 8**********************

import java.util.*;
import java.util.stream.*;
import java.util.function.Function;

class GFG {


    public static <T> Set<T> convertListToSet(List<T> list)
    {

        Set<T> set = new HashSet<>();


        for (T t : list)
            set.add(t);


        return set;
    }

    public static void main(String args[])
    {


        List<String> list = Arrays.asList("Rishabh",
                                          "Kumar",
                                          "WebD",
                                          "Hacktoberfest",
                                          "GitHub",
                                          "OpenSource");


        System.out.println("List: " + list);


        Set<String> set = convertListToSet(list);


        System.out.println("Set from List: " + set);
    }
}
