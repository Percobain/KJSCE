public class NumException extends Exception {
    public NumException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "NumException: " + getMessage();
    }
}
