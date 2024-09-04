package shiyan6_2;

public class Test {

	public static void main(String[] args) {
		KFC_Factory factory = new Hamburg_Factory();
		Food food1 = factory.produce();
		food1.show();
	}

}
