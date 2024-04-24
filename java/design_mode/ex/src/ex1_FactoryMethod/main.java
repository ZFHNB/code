package ex1_FactoryMethod;

public class main {
    public static void main(String[] args) {
        PenCore penCore;
        BallPen ballPen = new RedBallPen();
        penCore = ballPen.getPenCore();
        penCore.writeBoard("Hello World");
    }
}
