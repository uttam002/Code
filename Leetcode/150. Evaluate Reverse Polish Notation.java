class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        int operand1,operand2;
        for(String token:tokens){
            if (Character.isDigit(token.charAt(0)) || (token.length() > 1 && Character.isDigit(token.charAt(1)))) {
                stack.push(Integer.parseInt(token));
            }
            else {
                operand2 = stack.pop();
                operand1 = stack.pop();
                 switch (token) {
                    case "+":
                        stack.push(operand1 + operand2);
                        break;
                    case "-":
                        stack.push(operand1 - operand2);
                        break;
                    case "*":
                        stack.push(operand1 * operand2);
                        break;
                    case "/":
                        stack.push(operand1 / operand2);
                        break;
                    case "%":
                        stack.push(operand1 % operand2);
                        break;
                }
            }
        }
        return stack.pop();
    }
}
