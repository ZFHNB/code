package shiyan4_2;

public class Test {

	public static void main(String[] args) {
		Computer computer = new Computer();
		Socket socket = new Socket();
		Adapter adapter = new Adapter(socket);
		adapter.powerOne();

	}

}
