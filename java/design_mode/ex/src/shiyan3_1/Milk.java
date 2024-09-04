package shiyan3_1;

public class Milk extends Decorator{

	public Milk(Beverage beverage) {
		this.beverage = beverage;
	}
	@Override
	public int getPrice() {
		return beverage.getPrice()+3;
	}

	@Override
	public String getName() {
		return beverage.getName()+"¼ÓÅ£ÄÌ";
	}

}
