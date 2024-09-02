package shiyan4_1;

public class TestAdapter {

	public static void main(String[] args) {

		Hotel hotel = new Hotel();
		DBSocket bDbSocket = new DBSocket();
		hotel.setSocket(bDbSocket);
		hotel.charge();
		
		GBSocketInterface gbSocket = new GBSocket();
		SocketAdapter adapter = new SocketAdapter(gbSocket);
		hotel.setSocket(adapter);
		hotel.charge();
	}

}
