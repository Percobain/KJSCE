package myPackage;

public class Trigonometry {
   
    public static double sine(int degree) {
        switch (degree) {
            case 0: return 0;
            case 30: return 0.5;
            case 60: return 0.866; 
            case 90: return 1;
            default: return Double.NaN;
        }
    }

   
    public static double cos(int degree) {
        switch (degree) {
            case 0: return 1;
            case 30: return 0.866; // sqrt(3)/2
            case 60: return 0.5;
            case 90: return 0;
            default: return Double.NaN; 
        }
    }

    
    public static double tan(int degree) {
        switch (degree) {
            case 0: return 0;
            case 30: return 0.577; 
            case 60: return 1.732; 
            case 90: return Double.POSITIVE_INFINITY; 
            default: return Double.NaN; 
        }
    }

    
    public static double cot(int degree) {
        switch (degree) {
            case 0: return Double.POSITIVE_INFINITY; 
            case 30: return 1.732; 
            case 60: return 0.577; 
            case 90: return 0;
            default: return Double.NaN; 
        }
    }

    public static double cosec(int degree) {
        switch (degree) {
            case 0: return Double.POSITIVE_INFINITY; 
            case 30: return 2;
            case 60: return 1.154; 
            case 90: return 1;
            default: return Double.NaN; 
        }
    }

    public static double sec(int degree) {
        switch (degree) {
            case 0: return 1;
            case 30: return 1.154; 
            case 60: return 2;
            case 90: return Double.POSITIVE_INFINITY; 
            default: return Double.NaN; 
        }
    }
}

