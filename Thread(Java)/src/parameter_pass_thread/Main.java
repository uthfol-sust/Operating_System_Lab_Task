package lab2;

public class Main {
    public static void main(String[] args) {
        Thread th1 = new Thread(new MyThread("Alice",23));
        Thread th2 = new Thread(new MyThread("Bob",20));

        th1.start();
        th2.start();

        try{
            th1.join();
            th2.join();
        }catch (Exception e){
            System.out.println("Exception");
        }
    }
}
