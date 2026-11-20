package restaurant;

public class Demarrage implements Runnable {
    @Override
    public void run() {
        Restaurant restaurant = new Restaurant();
        Placier placier = new Placier(restaurant);
        placier.setVisible(true);
    }
}