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
		System.out.println("用户2接收到的消息是：新闻发布的年份"+year);
		
	}

}
