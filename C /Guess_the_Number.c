import java.util.Arrays;

public class GuessTheNumber {

    public static void main(String[] args) {
        System.out.println(guessNumber(2500, new String[]{"X+10", "X-5", "X*5", "X^2"}));  // Output: 5
        System.out.println(guessNumber(1000, new String[]{"X*5", "X/0", "X^3"}));  // Output: -1
        System.out.println(guessNumber(10, new String[]{"X*5", "X*0", "X+10"}));  // Output: -2
        System.out.println(guessNumber(617283948, new String[]{"X+5", "X-0", "X+1", "X/2", "X^1"}));  // Output: 1234567890
    }
    
    public static double guessNumber(int finalNumber, String[] operations) {
        double X = finalNumber; // Assigning finalNumber to X
        
        
        operations = Arrays.stream(operations).map(s -> s.replace("X", "")).toArray(String[]::new); // Removing X from the operations
        for(int i=operations.length-1;i>=0;i--) {
            if(operations[i].contains("+")) {
                X = X - Double.parseDouble(operations[i].replace("+", "")); // Subtracting the value from X
            } else if(operations[i].contains("-")) {
                X = X + Double.parseDouble(operations[i].replace("-", "")); // Adding the value to X
            } else if(operations[i].contains("*")) {
                if(Double.parseDouble(operations[i].replace("*", "")) == 0) {
                    return -2; // If the value is 0, return -1
                }
                X = X / Double.parseDouble(operations[i].replace("*", "")); // Dividing the value from X
            } else if(operations[i].contains("/")) {
                if(Double.parseDouble(operations[i].replace("/", "")) == 0) {
                    return -1; // If the value is 0, return -1
                }
                X = X * Double.parseDouble(operations[i].replace("/", "")); // Multiplying the value to X
            } else if(operations[i].contains("^")) {
                X = Math.pow(X, (1/Double.parseDouble(operations[i].replace("^", "")))); // Power of X
            }else {
                return -1;
            }

        }
           
        return X; // Return the final calculated value
    }
}
