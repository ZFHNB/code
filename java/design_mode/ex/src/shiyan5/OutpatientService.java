package shiyan5;

public class OutpatientService {
	public String describe;
	

	public OutpatientService(String describe) {
		this.describe = describe;
		System.out.println("���������" + describe);
	}

	public String check(){
		return describe;
	}
}
