package shiyan7;

public class LenovoPhone extends Phone{

	private static int id = 2000;
	public LenovoPhone() {
		mark = "����";
	}
	@Override
	public int getId() {
		return id++;
	}

}
