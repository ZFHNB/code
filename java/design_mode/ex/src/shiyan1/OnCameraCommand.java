package shiyan1;

public class OnCameraCommand implements Command{
	Camera camera;
	public OnCameraCommand(Camera camera) {
		this.camera = camera;
	}
	@Override
	public void execute() {
		camera.on();
		
	}
	@Override
	public String getName() {
		return "ÃüÁî£º´ò¿ªÉãÏñÍ·";
	}
	
}
