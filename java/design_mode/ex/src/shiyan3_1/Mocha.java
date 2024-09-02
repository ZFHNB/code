package shiyan3_1;

public class Mocha extends Decorator{
	
	public Mocha(Beverage beverage) {
		this.beverage = beverage;
	}
	@Override
	public int getPrice() {
		return beverage.getPrice()+4;
	}

	@Override
	public String getName() {
		return beverage.getName()+"¼ÓÄ¦¿¨";
	}

}

