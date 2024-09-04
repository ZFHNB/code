package shiyan6_1;

public class LenocoFactory extends AbstractFactory{

	@Override
	public Laptop produce() {
		return new LenovoLaptop();
	}

}
