package shiyan6_1;
public class AppleLaptop extends Laptop{

	public static int id = 1000;
	
	public AppleLaptop() {
		name = "Æ»¹û";
	}
	@Override
	public int getId() {
		return id++;
	}

}
