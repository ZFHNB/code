package shiyan6_1;

public class Test {

	public static void main(String[] args) {
		AbstractFactory factory = new LenocoFactory();
		Laptop laptop =  factory.produce();
		laptop.show();
		
	}

}
