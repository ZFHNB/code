package shiyan2_1;

public class ReaderTwo implements Reader{

	@Override
	public void update(String news) {
		System.out.println("ReaderTwo接收到了"+news);		
	}
}
