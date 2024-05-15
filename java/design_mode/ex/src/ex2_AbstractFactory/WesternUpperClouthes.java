package ex2_AbstractFactory;

public class WesternUpperClouthes extends UpperClouthes{
    private int chestSize = 0;
    private int height = 0;
    private String name;

    public WesternUpperClouthes(String name, int chestSize, int height) {
        this.name = name;
        this.chestSize = chestSize;
        this.height = height;
    }
    public int getChestSize(){       return chestSize;   }
    public int getHeight(){       return height;   }
    public String getName(){      return name;   }    

}
