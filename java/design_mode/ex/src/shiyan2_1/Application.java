package shiyan2_1;

public class Application {
	public static void main(String[] args) {
		RssData rssData = new RssData("���������ڶ�");
		ReaderOne readerOne = new ReaderOne();
		ReaderTwo readerTwo = new ReaderTwo();	
		rssData.subscribeRSS(readerOne);
		rssData.subscribeRSS(readerTwo);
		rssData.notifyReader();
	}

}
