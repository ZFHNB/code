package ex1_FactoryMethod;

public class RedBallPen extends BallPen 
{
    public PenCore getPenCore()
    {
        return new RedPenCore();
    }
}