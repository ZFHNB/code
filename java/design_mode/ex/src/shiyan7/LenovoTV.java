package shiyan7;

public class LenovoTV extends TV {
	private static int id = 5000;

	public LenovoTV() {
		mark = "БЄПл";
	}
	@Override
	public int getId() {
		return id++;
	}
	
	
}
