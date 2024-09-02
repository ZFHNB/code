package shiyan3_1;

public class Soy extends Decorator{
	
	public Soy(Beverage beverage) {
		this.beverage = beverage;
	}
	@Override
	public int getPrice() {
		return beverage.getPrice()+5;
	}

	@Override
	public String getName() {
		return beverage.getName()+"¼Ó¶¹½¬";
	}

}
