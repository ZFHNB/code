package ex1_FactoryMethod;

public class BlueBallPen extends BallPen{
    public PenCore getPenCore()
    {
        return new BluePenCore();
    }
}
