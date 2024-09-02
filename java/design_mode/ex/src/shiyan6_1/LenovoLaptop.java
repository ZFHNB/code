package shiyan6_1;

public class LenovoLaptop extends Laptop{

	public static int id = 500;//静态变量，保证每一个编号不唯一
	
	public LenovoLaptop() {
		name = "联想";
	}
	
	@Override
	public int getId() {
		return id++;
	}

}
