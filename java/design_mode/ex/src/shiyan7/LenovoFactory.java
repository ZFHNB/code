package shiyan7;

public class LenovoFactory implements Factory{

	@Override
	public Laptop produceLaptop() {
		return new LenovoLaptop();
	}

	@Override
	public Phone producePhone() {
		return new LenovoPhone();
	}

	@Override
	public TV produceTV() {
		// TODO Auto-generated method stub
		return new LenovoTV();
	}
}
