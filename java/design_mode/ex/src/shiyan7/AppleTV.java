package shiyan7;

public class AppleTV extends TV{
	private static int id = 3000;
	
	public AppleTV() {
		mark = "ƻ��";
	}
	@Override
	public int getId() {
		return id++;
	}

}
