package shiyan2_2;
import java.util.ArrayList;
import java.util.List;

public class RssData implements RSS{//������Ϣ
	private List<Reader> readers;
	private String name;
	private String year;

	
	public RssData(String name,String year){
		readers = new ArrayList<Reader>();
		this.name = name;
		this.year = year;
	}
	public void setNews(String news) {
		readers = new ArrayList<Reader>();
		this.name = news;
	}
	
	
	public String getName() {
		return name;
	}

	public String getYear() {
		return year;
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

			reader.update();
		}	
	}
	
}
