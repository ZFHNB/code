package shiyan7;

public class AppleTV extends TV{
	private static int id = 3000;
	
	public AppleTV() {
		mark = "Æ»¹û";
	}
	@Override
	public int getId() {
		return id++;
	}

}
