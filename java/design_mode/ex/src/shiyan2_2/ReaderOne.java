package shiyan2_2;

public class ReaderOne implements Reader{

	RssData rss;
	String name;

	public ReaderOne(RssData rss) {
		this.rss = rss;
	}
	
	@Override
	public void update() {
		name = rss.getName();
		System.out.println("�û�1���յ�����Ϣ�ǣ����ŷ�������"+name);
		
	}

}
