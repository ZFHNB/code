package shiyan4_2;

public class Adapter implements ComputerInterface{

	SocketInterface socket;
	
	public Adapter(SocketInterface socket) {
		this.socket = socket;
	}
	@Override
	public void powerOne() {
		System.out.println("���ǵ�ѹת�������ҽ���Ҫ���ѹ����Ҫ��Ϊ" + dianya + "V��" + name);
		socket.powerTwo();
		System.out.println("Ϊ�ҹ���");
		
	}

}
