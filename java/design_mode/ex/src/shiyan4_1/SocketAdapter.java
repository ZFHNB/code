package shiyan4_1;

public class SocketAdapter implements DBSocketInterface{

	//目标接口的实例引用
	private GBSocketInterface gbSocket;
	
	public SocketAdapter(GBSocketInterface gbSocketInterface) {
		gbSocket = gbSocketInterface;
	}
	@Override
	public void powerWithTwoRound() {
		gbSocket.powerWithThreeFlat();
	}

}
