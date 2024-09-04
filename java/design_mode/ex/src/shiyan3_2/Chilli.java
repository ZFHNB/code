package shiyan3_2;

public class Chilli extends Condiment{
	public Chilli(Hamburger hamburger) {
		this.hamburger = hamburger;
	}

	@Override
	public String getName() {
		return hamburger.getName()+"º”¿±Ω∑";
	}

	@Override
	public Double getPrice() {
		return hamburger.getPrice()+0.5;
	}
}
