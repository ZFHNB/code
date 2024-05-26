package ex_FacadeMonthTest;

public class Package {
    private int weight;
    private boolean isSafe = true;
    public Package(int weight, boolean isSafe)
    {
        this.weight = weight;
        this.isSafe = isSafe;
    }
    public int getWeight() 
    {
        return this.weight;
    }
    public boolean getIsSafe()
    {
        return this.isSafe;
    }
}
