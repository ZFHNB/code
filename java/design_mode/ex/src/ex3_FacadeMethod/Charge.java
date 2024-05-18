package ex3_FacadeMethod;

public class Charge
{
    public final int basicCharge = 10;
    public CheckWord checkWord;

    public Charge(CheckWord checkWord)
    {
        this.checkWord = checkWord;
    }
    public void getCharge()
    {
        int charge = basicCharge * checkWord.getAmount();
        System.out.println("广告费用为："+charge);
    }
}
