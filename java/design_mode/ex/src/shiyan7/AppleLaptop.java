package shiyan7;

public class AppleLaptop extends Laptop{
	
	private static int id = 1000;

	public AppleLaptop() {
		mark = "Æ»¹û";
	}
	@Override
	public int getId() {
		return id++;
	}
	
}
