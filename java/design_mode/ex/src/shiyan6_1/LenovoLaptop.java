package shiyan6_1;

public class LenovoLaptop extends Laptop{

	public static int id = 500;//��̬��������֤ÿһ����Ų�Ψһ
	
	public LenovoLaptop() {
		name = "����";
	}
	
	@Override
	public int getId() {
		return id++;
	}

}
