package shiyan7;

public class LenovoLaptop extends Laptop{

	private static int id = 500;//��̬��������֤ÿһ����Ų�Ψһ
	
	public LenovoLaptop() {
		mark = "����";
	}
	@Override
	public int getId() {
		return id++;
	}

}
