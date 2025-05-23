public class Main {
    public static void main(String[] args) {


            Thread t1 =new Thread(new ThreadCreation(23,"Anis"));
            Thread t2 = new Thread(new ThreadCreation(19,"Uthpol"));

            t1.start();
            t2.start();

            try{
                t1.join();
                t2.join();
            }catch(Exception e){
                System.out.println("Thread interrupted");
            }
            System.out.println("Main thread finished.");
    }
}
