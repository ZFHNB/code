package ex_FacadeMonthTest;

public class Weight {
    private final int base = 10;
    private int weight;
    Weight(Package pkg)
    {
        this.weight = pkg.getWeight();
    }
    public int Charge()
    {
        return base * weight;
    }
}
