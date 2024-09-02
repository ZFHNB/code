package shiyan8;

public class Test {

	public static void main(String[] args) {
		//类方法通过类名去调用，因为此时无法从外部创建对象,只能将得到唯一对象的方法设置为静态方法
		Moon moon = Moon.getMoon();
		moon.show();
	}

}
