package shiyan3_2;

public class Sauce extends Condiment{

	public Sauce(Hamburger hamburger) {
		this.hamburger = hamburger;
	}
	@Override
	public String getName() {
		return hamburger.getName()+"�ӽ�";
	}

	@Override
	public Double getPrice() {
		return hamburger.getPrice()+1.5;
	}

}
