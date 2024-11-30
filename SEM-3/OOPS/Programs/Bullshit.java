
import java.util.Vector;

public class Bullshit {
    public static void main(String[] args) {
        // ArrayList<String> cars = new ArrayList<String>();
        // cars.add("Volvo");
        // cars.add("BMW");
        // cars.add("Ford");
        // cars.add("Mazda");

        // Iterator<String> it = cars.iterator();
        // while(it.hasNext()) {
        //     System.out.println(it.next());
        // }

        Vector<String> stringList = new Vector<String>();
        stringList.add("Spring");
        stringList.add("Summer");
        stringList.add("Fall");
        stringList.add("Winter");

        for(String s : stringList) {
            System.out.println(s);
        }
    }
}