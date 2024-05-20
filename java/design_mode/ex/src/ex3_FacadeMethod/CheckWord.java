package ex3_FacadeMethod;

public class CheckWord 
{
    public final int basicAmount = 85;
    public String advertisement;
    public int amount;

    public CheckWord(String advertisement)
    {
        this.advertisement = advertisement;
    }
    public void setChargeAmount()
    {
        amount = advertisement.length() + basicAmount;
    }
    public int getAmount() 
    {
        return amount;
    }
}