package shiyan1;

public class OnLightCommand implements Command{
	Light light;
	public OnLightCommand(Light light ) {
		this.light = light;
	}
	@Override
	public void execute() {
		light.on();
		
	}
	@Override
	public String getName() {
		return "ÃüÁî£º´ò¿ªµÆ";
	}
	
}
