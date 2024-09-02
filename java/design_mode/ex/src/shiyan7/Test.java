package shiyan7;

public class Test {

	public static void main(String[] args) {
		Factory factory = new LenovoFactory();
		TV tv = factory.produceTV();
		tv.printInfo();
		Phone phone = factory.producePhone();
		phone.printInfo();
		
	}

}
