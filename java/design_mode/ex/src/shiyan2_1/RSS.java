package shiyan2_1;

public interface RSS {//��������
	public void subscribeRSS(Reader reader);
	public void cancelRSS(Reader reader);
	public void notifyReader();
}
