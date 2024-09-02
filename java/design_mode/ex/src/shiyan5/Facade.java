package shiyan5;

public class Facade {
	Register register;
	OutpatientService service;
	Price price;
	Pharmacy pharmacy;
	
	public Facade(String describe) {
		register = new Register();
		service = new OutpatientService(describe);
		pharmacy = new Pharmacy(describe);
	}
	
	public void  seeDoctor() {
		register.setRegister();
		if((register.getIsregister())==true){
			System.out.println("Ω®“È“©∆∑£∫"+ pharmacy.getName());
		}
		else {
			System.out.println("Œ¥π“∫≈£¨«Îœ»π“∫≈");
		}
	}
}
