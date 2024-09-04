package shiyan2_2;

public interface RSS {//³éÏóÖ÷Ìâ
	public void subscribeRSS(Reader reader);
	public void cancelRSS(Reader reader);
	public void notifyReader();
}
