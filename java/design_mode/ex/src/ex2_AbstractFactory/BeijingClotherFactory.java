package ex2_AbstractFactory;

public class BeijingClotherFactory extends ClouthesFactory{
    @Override
    public UpperClouthes createUpperClouthes() {
        return new WesternUpperClouthes(null, 0, 0);
    }
    @Override
    public Trousers creatTrousers() {
        return new WesternTrousers(null, 0, 0);
    }
}
