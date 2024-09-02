package shiyan3_1;

public class CoffeeBean1 extends Beverage{

	public CoffeeBean1() {
		price = 10;
		name = "µÚÒ»ÖÖ¿§·È";
	}
	@Override
	public int getPrice() {
		return price;
	}

	@Override
	public String getName() {
		return name;
	}

}
