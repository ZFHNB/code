package ex1_FactoryMethod;

public class main {
    public static void main(String[] args) 
    {

        BallPen redBallPen = new RedBallPen();
        BallPen blueBallPen = new BlueBallPen();

        PenCore redPenCore = redBallPen.getPenCore();
        PenCore bluePenCore = blueBallPen.getPenCore();

        redPenCore.writeWord("我是红笔写出来的");
        bluePenCore.writeWord("我是蓝笔写出来的");
    }
}
