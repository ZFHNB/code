package shiyan3_2;

public class Lettuce extends Condiment{

	public Lettuce(Hamburger hamburger) {
		this.hamburger = hamburger;
	}
	@Override
	public String getName() {
		return hamburger.getName()+"������";
	}

	@Override
	public Double getPrice() {
		return hamburger.getPrice()+1.0;
	}

}
