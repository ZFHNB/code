package shiyan7;

public class AppleLaptop extends Laptop{
	
	private static int id = 1000;

	public AppleLaptop() {
		mark = "ƻ��";
	}
	@Override
	public int getId() {
		return id++;
	}
	
}
