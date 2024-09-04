package shiyan2_1;

public class ReaderOne implements Reader{

	@Override
	public void update(String news) {
		System.out.println("ReaderOne接收到了"+news);	
	}
}
