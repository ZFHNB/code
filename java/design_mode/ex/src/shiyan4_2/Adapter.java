package shiyan4_2;

public class Adapter implements ComputerInterface{

	SocketInterface socket;
	
	public Adapter(SocketInterface socket) {
		this.socket = socket;
	}
	@Override
	public void powerOne() {
		System.out.println("我是电压转换器，我接收要求电压输入要求为" + dianya + "V的" + name);
		socket.powerTwo();
		System.out.println("为我供电");
		
	}

}
