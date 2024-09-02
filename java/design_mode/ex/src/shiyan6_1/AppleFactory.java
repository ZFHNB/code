package shiyan6_1;

public class AppleFactory extends AbstractFactory{

	@Override
	public Laptop produce() {
		return new AppleLaptop();
	}

}
