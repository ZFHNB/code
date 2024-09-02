package shiyan7;

public class LenovoLaptop extends Laptop{

	private static int id = 500;//静态变量，保证每一个编号不唯一
	
	public LenovoLaptop() {
		mark = "联想";
	}
	@Override
	public int getId() {
		return id++;
	}

}
