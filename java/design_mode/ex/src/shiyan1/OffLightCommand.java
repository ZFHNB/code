package shiyan1;

public class OffLightCommand implements Command{
	Light light ;
	public OffLightCommand(Light light) {
		this.light = light;
	}
	@Override
	public void execute() {
		light.off();
		
	}
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return "√¸¡Ó£∫πÿ±’µ∆";
	}

}
