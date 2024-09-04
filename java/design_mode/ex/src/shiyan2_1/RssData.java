package shiyan2_1;
import java.util.ArrayList;
import java.util.List;

public class RssData implements RSS{//������Ϣ
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
		// ���۲�����ӵ�������
		readers.add(reader);
	}
	@Override
	public void cancelRSS(Reader reader) {
		// ���۲��ߴ�������ɾ��
		readers.remove(reader);
	}
	@Override
	public void notifyReader() {
		// ����Ϣ֪ͨ���е��û�
		for (Reader reader : readers) {
			reader.update(news);
		}	
	}
	
}
