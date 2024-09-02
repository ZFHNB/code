package shiyan2_1;
import java.util.ArrayList;
import java.util.List;

public class RssData implements RSS{//具体消息
	private List<Reader> readers;
	private String news;
	
	public RssData() {
	}
	public RssData(String news){
		readers = new ArrayList<Reader>();
		this.news = news;
	}
	
	public void setNews(String news) {
		readers = new ArrayList<Reader>();
		this.news = news;
	}
	
	public String getNews(){
		return news;
	}
	
	@Override
	public void subscribeRSS(Reader reader) {
		// 将观察者添加到主题中
		readers.add(reader);
	}
	@Override
	public void cancelRSS(Reader reader) {
		// 将观察者从主题中删除
		readers.remove(reader);
	}
	@Override
	public void notifyReader() {
		// 将消息通知所有的用户
		for (Reader reader : readers) {
			reader.update(news);
		}	
	}
	
}
