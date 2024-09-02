package shiyan7;

public class ApplePhone extends Phone{
	private static int id = 3000;
	
	public ApplePhone() {
		mark = "Æ»¹û";
	}
	@Override
	public int getId() {
		return id++;
	}

}
