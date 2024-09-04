package shiyan6_2;

public class Chips_Factory extends KFC_Factory{

	@Override
	public Food produce() {
		return new Chips();
	}

}
