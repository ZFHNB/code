package shiyan6_2;

public class Hamburg_Factory extends KFC_Factory{

	@Override
	public Food produce() {
		return new Hamburg();
	}

}
