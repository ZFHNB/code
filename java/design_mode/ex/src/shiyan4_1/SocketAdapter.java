package shiyan4_1;

public class SocketAdapter implements DBSocketInterface{

	//Ŀ��ӿڵ�ʵ������
	private GBSocketInterface gbSocket;
	
	public SocketAdapter(GBSocketInterface gbSocketInterface) {
		gbSocket = gbSocketInterface;
	}
	@Override
	public void powerWithTwoRound() {
		gbSocket.powerWithThreeFlat();
	}

}
