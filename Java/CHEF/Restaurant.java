import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Order {
    int id;
    String name;
    int time;

    Order(int id, String name, int time) {
        this.id = id;
        this.name = name;
        this.time = time;
    }
}

class Chef implements Runnable {
    private final List<Order> orders;
    private final int chefId;

    Chef(List<Order> orders, int chefId) {
        this.orders = orders;
        this.chefId = chefId;
    }

    @Override
    public void run() {
        while (true) {
            Order order;
            synchronized (orders) {
                if (orders.isEmpty()) {
                    break;  // No more orders to process
                }
                order = orders.remove(0);
            }

            System.out.println("Order #" +order.id+" assigned to Chef #" +this.chefId+ " (" + order.name + ")");
            System.out.println("Order #" +order.id+" is in progress. " + "(" + order.name + ")");
            try {
                TimeUnit.SECONDS.sleep(order.time);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Order #" + order.id + " is ready. "+ " (" + order.name + ")");
        }
    }
}

public class Restaurant {
    public static void main(String[] args) {
        List<Order> orders = new ArrayList<>();
        orders.add(new Order(1, "Burger", 6));
        orders.add(new Order(2, "Salad", 3));
        orders.add(new Order(3, "Sundae", 4));
        orders.add(new Order(4, "Pizza", 8));
        orders.add(new Order(5, "Pasta", 7));
        orders.add(new Order(6, "Steak", 9));
        orders.add(new Order(7, "Soup", 2));

        int numChefs = 3;
        ExecutorService executor = Executors.newFixedThreadPool(numChefs);

        for (int i = 1; i <= numChefs; i++) {
            executor.submit(new Chef(orders, i));
        }

        executor.shutdown();
        try {
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
