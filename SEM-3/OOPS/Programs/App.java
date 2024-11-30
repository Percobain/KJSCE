import java.util.Random;

class Generator extends Thread {
    private final Processor processor;

    public Generator(Processor processor) {
        this.processor = processor;
    }

    @Override
    public void run() {
        Random r = new Random();
        while (true) {
            int n = r.nextInt(1000);
            System.out.println("Generated: " + n);
            processor.process(n);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class Processor {
    public synchronized void process(int n) {
        if (n % 2 == 0) {
            new Calculator().square(n);
        } else {
            new Calculator().cube(n);
        }
    }
}

class Calculator {
    public void square(int n) {
        int s = n * n;
        System.out.println("Square: " + s);
    }

    public void cube(int n) {
        int c = n * n * n;
        System.out.println("Cube: " + c);
    }
}

public class App {
    public static void main(String[] args) {
        Processor p = new Processor();
        Generator g = new Generator(p);
        g.start();
    }
}