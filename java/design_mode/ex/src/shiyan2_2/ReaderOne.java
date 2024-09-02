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
		System.out.println("用户1接收到的消息是：新闻发布者是"+name);
		
	}

}
