
import java.util.*;

public class sortSet {
	
		sortSet() {
		    System.out.println("Method");
		    this.doSomething();
		  }
	  public void doSomething(){
		    HashSet<toSort> mySet = new HashSet<toSort>();
		    int i;
		    toSort j = new toSort("perrp", 3);
		    for (i = 0; i<10 ; i++) {
		      System.out.println("Test" + i);
		      mySet.add(new toSort(String.valueOf(i), i));
		    }
		  }

	
	
	  public static void main(String[] args) {
	      System.out.println("Test");
	      sortSet self = new sortSet();
	  }
	  
	  class toSort {
		    private String name;
		    private int someProperty;

		    toSort(String nm, int prtpt){
		      name = nm;
		      someProperty = prtpt;
		    }

		    String getName(){
		      return(name);
		    }

		    int getProp(){
		      return someProperty;
		    }

		    void setName(String nm){
		      name = nm;
		    }

		    void setProp(int prop){
		      someProperty = prop;
		    }
		  }
	
}
