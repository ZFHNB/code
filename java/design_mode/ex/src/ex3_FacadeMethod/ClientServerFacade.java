package ex3_FacadeMethod;

public class ClientServerFacade 
{
    private CheckWord checkWord;
    private Charge charge;
    private TypeSeting typeSeting;
    String advertisement;

    public ClientServerFacade(String advertisement)
    {
        checkWord = new CheckWord(advertisement);
        charge = new Charge(checkWord);
        typeSeting = new TypeSeting(advertisement);
    }
    public void doAdvertisement()
    {
        checkWord.setChargeAmount();
        charge.getCharge();
        typeSeting.typeSeting();
    }
}
