package shiyan7;

public class AppleFactory implements Factory{

	@Override
	public Laptop produceLaptop() {
		return new AppleLaptop();
	}

	@Override
	public Phone producePhone() {
		return new ApplePhone();
	}

	@Override
	public TV produceTV() {
		return new AppleTV();
	}

}
