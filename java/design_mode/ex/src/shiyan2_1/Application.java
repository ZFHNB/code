package shiyan2_1;

public class Application {
	public static void main(String[] args) {
		RssData rssData = new RssData("今天是星期二");
		ReaderOne readerOne = new ReaderOne();
		ReaderTwo readerTwo = new ReaderTwo();	
		rssData.subscribeRSS(readerOne);
		rssData.subscribeRSS(readerTwo);
		rssData.notifyReader();
	}

}
