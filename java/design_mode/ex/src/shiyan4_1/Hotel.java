package shiyan4_1;

public class Hotel extends DBSocket{
	
	private DBSocketInterface dbSocket;
	public void setSocket(DBSocketInterface db){
		dbSocket = db;
	}
	public void charge(){//³äµç
		dbSocket.powerWithTwoRound();
	}
}
