package shiyan2_2;

public class ReaderTwo implements Reader{

	RssData rss;
	String year;

	public ReaderTwo(RssData rss) {
		this.rss = rss;
	}
	
	@Override
	public void update() {
		year = rss.getYear();
		System.out.println("�û�2���յ�����Ϣ�ǣ����ŷ��������"+year);
		
	}

}
