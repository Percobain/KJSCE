public class jagarray {
    public static void main(String[] args){
        int first[][] = new int[3][];
        first[0] = new int[4];
        first[1] = new int[3];
        first[2] = new int[2];

        int second[][] = new int[2][];
        second[0] = new int[3];
        second[1] = new int[4];

        for (int i = 0; i < first.length; ++i) {
            for (int j = 0; j < first[i].length; ++j) {
                first[i][j] = i + j;
            }
        }

        for (int i = 0; i < second.length; ++i) {
            for (int j = 0; j < second[i].length; ++j) {
                second[i][j] = i + j + 1;
            }
        }

        System.out.println("First 2D Array: ");
        printJaggedArray(first);

        System.out.println("Second 2D Array: ");
        printJaggedArray(second);
        
    }

    public static void printJaggedArray(int arr[][]) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr[i].length; ++j) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
