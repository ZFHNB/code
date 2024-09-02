package shiyan2_2;

public class Application {

	public static void main(String[] args) {
		RssData rssData = new RssData("发布者1","2021年");
		ReaderOne readerOne = new ReaderOne(rssData);
		ReaderTwo readerTwo = new ReaderTwo(rssData);
		
		rssData.subscribeRSS(readerOne);
		rssData.subscribeRSS(readerTwo);
		rssData.notifyReader();
		
	}

}
